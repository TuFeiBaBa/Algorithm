#include <vector>
#include <algorithm>
using namespace std;

/**
* 网络延迟时间:https://leetcode.cn/problems/network-delay-time/
*
* 隐藏陷阱：
*	1.a->c不一定是最短的路径，可能a->b->c是最短路径。
*	2.图没有说是有向无环的，而且，起点是固定的，但起点不保证是入度为0。所以拓扑排序是不适用的。
*	3.1 <= k <= n <= 100，1 <= times.length <= 6000。（顶点最多100个，但是边却可能高达6000条，所以，这可能是个稠密图，侧面反映了很可能是有环的）
*	4."需要多久才能使所有节点都收到信号？"信号发送的过程不是DFS的，而是BFS，是可分裂的，即有分岔路时，信号会分裂（或者说复制），以便向不同路径发送。
*
* Dijkstra算法：
*	核心思想：「未确定节点」和「已确定节点」
*		1.将所有节点分成两类：已确定从起点到当前点的最短路长度的节点，以及未确定从起点到当前点的最短路长度的节点。
*		2.每次从「未确定节点」中取一个与起点距离最短的点，将它归类为「已确定节点」，并用它「更新」从起点到其他所有「未确定节点」的距离。直到所有点都被归类为「已确定节点」。
*		3.用节点 A「更新」节点 B 的意思是，用起点到节点 A 的最短路长度加上从节点 A 到节点 B 的边的长度，去比较起点到节点 B 的最短路长度，如果前者小于后者，就用前者更新后者。这种操作也被叫做「松弛」。
*		（这里暗含的信息是：每次选择「未确定节点」时，起点到它的最短路径的长度可以被确定）
*	优化思想：观察枚举法：
*		1.选择一个新的「已确定节点」时，只能通过遍历比较每个未确定节点与起点的dist大小，再选择最小的一个出来，时间复杂度是O(n)。所以，可以采用【优先队列】优化成O(logn)
*		2.存图方式：用了邻接矩阵。从提示里的数据来看，图大概率是稠密图。所以优先选择【邻接矩阵】。
*			1.邻接矩阵：节点数为V，则使用一个V^2的矩阵，来存储点与点之间的连接关系。适合当边数量接近点的数量的平方，即 【V^2≈E】 时，即适合【稠密图】。
*			2.邻接表：用一个以顶点为索引的列表数组，其中的每个元素都是和该顶点相邻的顶点列表。适合当边数量接近点的数量，即 【V≈E】 时，即适合【稀疏图】。
*			3.边的数组：用一个类表示边。然后用数组，把所有的边对象存储起来。只有当我们需要确保某个操作复杂度严格为 【O(E)】 时，才会考虑使用。
*		   提到三种存图方式的解法：https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/
*		
*/
class Solution {
public:
	//朴素写法：枚举法
	//时间复杂度：O(n^2+ m)，其中 m 是数组 times 的长度。
	//空间复杂度：O(n^2)。邻接矩阵需占用 O(n^2)的空间。
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		const int inf = INT_MAX / 2;
		vector<vector<int>> g(n, vector<int>(n, inf));
		for (auto& t : times) {
			int x = t[0] - 1, y = t[1] - 1;
			g[x][y] = t[2];
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0;
		vector<int> used(n);
		for (int i = 0; i < n; ++i) {
			int x = -1;
			for (int y = 0; y < n; ++y) {
				if (!used[y] && (x == -1 || dist[y] < dist[x])) {
					x = y;
				}
			}
			used[x] = true;
			for (int y = 0; y < n; ++y) {
				dist[y] = min(dist[y], dist[x] + g[x][y]);
			}
		}
		//max_element是用来来查询最大值所在的第一个位置。所以需要*来解引用，获取最大值。
		int ans = *max_element(dist.begin(), dist.end());
		return ans == inf ? -1 : ans;
	}
};

int main() {

}