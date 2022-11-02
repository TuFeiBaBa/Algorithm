#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
* ��Ԫ�飺c++ : tuple	Java:triple
*/

/**
*
* �ⷨһ��dijkstra�㷨����
*	˼·��
*		1.�ó����dijkstra�����ǲ��еġ��޷�����k�����ơ�
*		2.���԰�k�����Ƽ����ж������У�����������dijkstra�����ɳڣ�
*			- ���·����һ��������k���ƣ�������ͼ/img/graph/cheapest-flights-within-k-stops/1.png��ʾ��
*			  �ɳڲ������ܵ��£��������ڿɴ�·����ȴ���ɳڲ������������ˡ����ԣ�Ӧ��ȥ��dict[y] > d����жϣ�����ȥ�� if(d > dict[x]) continue
*		3.Ԥ������Ŀ����֤ͼ����ͨ�ġ�����dst���ɴ��û�н���dijkstra�ı�Ҫ�ˡ������dijkstra��ʱ�临�Ӷ���O((V + E)logV)��
*		  ���ֺ��ʱ�临�Ӷ���Ȼ�����������ͼ�Ƿ���ͨ��ʱ�临�Ӷ���O(V + E)
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
//			//vector��emplace��emplace_back��ɶ����
//			//emplace_back����ĩβ���룬emplace����ָ���ĵ������������
//			graph[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
//		}
//		bool conn = isConnect(graph, src, dst);
//		if (!conn) return -1;
//
//		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
//		//��emplace������emplace_back
//		q.emplace(0, k, src);
//		while (!q.empty()) {
//			tuple<int,int,int> t = q.top();
//			int price = get<0>(t);
//			int cnt = get<1>(t);
//			int city = get<2>(t);
//			q.pop();
//			//city��"ȷ������"�������Ѿ��ҵ������·����
//			if (city == dst) {
//				return city;
//			}
//
//			for (auto& e : graph[city]) {
//				//û��ִ���ɳڣ���û��dict[y] > d
//				if (get<1>(t) >= 0) {
//					q.emplace(get<0>(t) + e.second, cnt - 1, e.first);
//				}
//			}
//		}
//		return -1;
//	}
//};

/**
*  K վ��ת������˵ĺ��� https://leetcode.cn/problems/cheapest-flights-within-k-stops/
*
*  Bellman-Ford�㷨�������Ͼ��Ƕ�̬�滮��
*		���裺
*			1.��ʼ��������dict[src]��ʼ��Ϊ0�������ʼ��Ϊmax������Ϊ���޶�ֻ��src��Ϊ�����㡣
*			2.����������������һ�������ǵڼ�������������ҪĿ����Ϊ�˱������еıߡ�
*			3.dict[limit][y] = min(dict[limit][y], dict[limit - 1][i] + d) ���ӵ�limit - 1�����ƶϵ�limit���ߵ�y�Ľ��
*
*  �㷨Ӧ�ó�����https://blog.csdn.net/qq_40597059/article/details/88027140
*			1.��⾭��������k���ߵ����·
*			2.��⾭��ǡ��k���ߵ����·�����ظ�������
*		������������Bellman-Ford �����Ż��汾Ӧ�ö������ðɣ��Ż��汾�ڱ��⣬Ҳ�����á���
*
*  ʱ�临�Ӷȣ�
*		�����ڽӾ���O(k * n^2)
*		�����ڽӱ�O(k(n + m))
*
*  ����һ���Ż������� Bellman Ford ���Ĳ�����Ҫ�������еıߣ����Ҳ����ֱ��ʹ�� flights ������Ϊ��ͼ��Ϣ������������ͼ��
*		�ο���https://leetcode.cn/problems/cheapest-flights-within-k-stops/solution/gong-shui-san-xie-xiang-jie-bellman-ford-dc94/
*/
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<pair<int, int>>> graph(n);
		int max = pow(10, 4) * 100 + 1;
		for (int i = 0; i < flights.size(); i++) {
			graph[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
		}
		//k + 1����Ϊ��ྭ��k�����㣬�Ǿ�����ྭ��k + 1����
		//k + 1 + 1����+1��������Ϊ�˳�ʼ�����Լ����������д����
		//�ڴ��Ż��������Ż���vector<int> dict��ֻ��Ҫ��ÿ�ν�����һ����ʱ�򣬿���һ����һ���ļ�¼���ɡ�
		//vector<vector<int>> dict(k + 2, vector<int>(n, max));
		//dict[0][src] = 0;
		//for (int limit = 1; limit < k + 2; limit++) {
		//	//��ʼ��
		//	dict[limit][src] = 0;
		//	for (int i = 0; i < n; i++) {
		//		for (auto& e : graph[i]) {
		//			int y = e.first;
		//			int d = e.second;
		//			//��֮ǰ���Ѿ����� limit - 1���ߵļ�¼
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
					//��д����dist[end] = min(copy[end], copy[i] + d)
					//����ԭ��ͬһ�ֱ����У����·����ǰ���Ѿ��������ˡ������ں��棬�ּ��������㣬
					//�Ƚϴ�С���õ�ȴ���Ǹ��º��ֵdist[end]�����Ǿɵ�ֵcopy[end]��
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