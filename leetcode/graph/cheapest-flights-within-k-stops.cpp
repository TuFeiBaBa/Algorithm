#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
* 三元组：c++ : tuple	Java:triple
*/

/**
*
* 解法一：dijkstra算法变种
*	思路：
*		1.用常规的dijkstra方法是不行的。无法处理k的限制。
*		2.可以把k的限制加入判断条件中，但不能再用dijkstra进行松弛：
*			- 最短路径不一定是满足k限制，而且如图/img/graph/cheapest-flights-within-k-stops/1.png所示，
*			  松弛操作可能导致，明明存在可达路径，却因松弛操作，被忽略了。所以，应该去掉dict[y] > d这个判断，还得去掉 if(d > dict[x]) continue
*		3.预处理：题目不保证图是连通的。假如dst不可达，就没有进行dijkstra的必要了。常规的dijkstra的时间复杂度是O((V + E)logV)，
*		  变种后的时间复杂度显然高于它。检测图是否连通的时间复杂度是O(V + E)
*/
//class Solution {
//
//private:
//	bool isConnect(vector<vector<pair<int, int>>>& graph, int src, int dst) {
//		queue<int> q;
//		vector<bool> visited(graph.size());
//		q.emplace(src);
//		while (!q.empty()) {
//			int x = q.front();
//			q.pop();
//			visited[x] = true;
//			for (auto& e : graph[x]) {
//				int y = e.first;
//				if (!visited[y]) q.emplace(y);
//			}
//		}
//		return visited[dst];
//	}
//
//public:
//	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//		vector<vector<pair<int, int>>> graph(n);
//	
//		for (int i = 0; i < flights.size(); i++) {
//			//vector的emplace和emplace_back有啥区别？
//			//emplace_back是在末尾插入，emplace是在指定的迭代器后面插入
//			graph[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
//		}
//		bool conn = isConnect(graph, src, dst);
//		if (!conn) return -1;
//
//		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
//		//是emplace，不是emplace_back
//		q.emplace(0, k, src);
//		while (!q.empty()) {
//			tuple<int,int,int> t = q.top();
//			int price = get<0>(t);
//			int cnt = get<1>(t);
//			int city = get<2>(t);
//			q.pop();
//			//city是"确定顶点"，所以已经找到了最短路径。
//			if (city == dst) {
//				return city;
//			}
//
//			for (auto& e : graph[city]) {
//				//没有执行松弛，即没有dict[y] > d
//				if (get<1>(t) >= 0) {
//					q.emplace(get<0>(t) + e.second, cnt - 1, e.first);
//				}
//			}
//		}
//		return -1;
//	}
//};

/**
*  K 站中转内最便宜的航班 https://leetcode.cn/problems/cheapest-flights-within-k-stops/
*
*  Bellman-Ford算法：本质上就是动态规划。
*		步骤：
*			1.初始化：除了dict[src]初始化为0。其余初始化为max。这是为了限定只以src作为出发点。
*			2.两层或三层遍历：第一层代表的是第几步。二三层主要目的是为了遍历所有的边。
*			3.dict[limit][y] = min(dict[limit][y], dict[limit - 1][i] + d) ：从第limit - 1步，推断第limit步走到y的结果
*
*  算法应用场景：https://blog.csdn.net/qq_40597059/article/details/88027140
*			1.求解经过不超过k条边的最短路
*			2.求解经过恰好k条边的最短路（可重复经过）
*		（上述场景，Bellman-Ford 队列优化版本应该都不适用吧？优化版本在本题，也不适用。）
*
*  时间复杂度：
*		采用邻接矩阵：O(k * n^2)
*		采用邻接表：O(k(n + m))
*
*  更进一步优化：由于 Bellman Ford 核心操作需要遍历所有的边，因此也可以直接使用 flights 数组作为存图信息，而无须额外存图。
*		参考：https://leetcode.cn/problems/cheapest-flights-within-k-stops/solution/gong-shui-san-xie-xiang-jie-bellman-ford-dc94/
*/
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<pair<int, int>>> graph(n);
		int max = pow(10, 4) * 100 + 1;
		for (int i = 0; i < flights.size(); i++) {
			graph[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
		}
		//k + 1，因为最多经过k个顶点，那就是最多经过k + 1条边
		//k + 1 + 1，多+1，仅仅是为了初始化，以及遍历代码好写而已
		//内存优化：可以优化成vector<int> dict，只需要在每次进行下一步的时候，拷贝一份上一步的记录即可。
		//vector<vector<int>> dict(k + 2, vector<int>(n, max));
		//dict[0][src] = 0;
		//for (int limit = 1; limit < k + 2; limit++) {
		//	//初始化
		//	dict[limit][src] = 0;
		//	for (int i = 0; i < n; i++) {
		//		for (auto& e : graph[i]) {
		//			int y = e.first;
		//			int d = e.second;
		//			//用之前的已经经过 limit - 1条边的记录
		//			dict[limit][y] = min(dict[limit][y], dict[limit - 1][i] + d);
		//		}
		//	}
		//}
		//int ans = max;
		//for (int i = 1; i < k + 2; i++) {
		//	ans = min(ans, dict[i][dst]);
		//}
		//return ans == max ? -1 : ans;

		vector<int> dist(n, max);
		dist[src] = 0;
		for (int step = 0; step < k + 1; step++) {
			vector<int> copy(dist);
			for (int i = 0; i < n; i++) {
				for (auto& e : graph[i]) {
					int end = e.first;
					int d = e.second;
					//误写成了dist[end] = min(copy[end], copy[i] + d)
					//错误原因：同一轮遍历中，最短路径在前面已经被更新了。但是在后面，又检测了这个点，
					//比较大小，用的却不是更新后的值dist[end]，而是旧的值copy[end]，
					dist[end] = min(dist[end], copy[i] + d);
				}
			}
		}
		return dist[dst] == max ? -1 : dist[dst];
	}
};

int main() {
	vector<vector<int>> flights{ {0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } };
	Solution su;
	int ans = su.findCheapestPrice(4, flights, 0, 3, 1);
}