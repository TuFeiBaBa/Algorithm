#include <vector>
#include <queue>
using namespace std;
/**
* 不邻接植花:https://leetcode.cn/problems/flower-planting-with-no-adjacent/
*
* 思路：
*   1.双向路径，即无向图
*   2.怎么染色？感觉没有什么特别好的办法。只能BFS或者DFS，在遍历边的过程中，
*     检查已visited的邻边使用了哪种花，挑剩下的花种即可。
*     (...还真是。所有花园最多有3条路径可以进入或者离开，只要检查邻边即可。)
*
* 陷阱：所有的花园不一定是一个连通分量。可能是多个连通分量。需要检查所有可能的起点。
*
* 这个题解写法更简洁：https://leetcode.cn/problems/flower-planting-with-no-adjacent/solution/cyan-se-biao-ji-by-liu-xiang-3-pivx/
* (直接遍历所有的顶点的边，只要在遍历过程中，检查邻边已经使用的颜色，再随便挑一个未使用颜色即可。(不需要以一个"起点"开始，遍历
*  连通分量，随机访问连通分量的任意一条边即可。相比下面的BFS的解法，少了不必要的检查起点的消耗))
*/
class Solution {
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<int> color(n);
		vector<vector<int>> graph(n + 1);
		for (int i = 0; i < paths.size(); i++) {
			graph[paths[i][0]].push_back(paths[i][1]);
			graph[paths[i][1]].push_back(paths[i][0]);
		}
		//循环是因为所有的花园不一定是一个连通分量。可能是多个连通分量
		//所以要检查所有可能的起点。
		for (int i = 1; i <= n; i++) {
			if (color[i - 1] > 0) continue;
			queue<int> q;
			q.push(i);
			color[i - 1] = 1;
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int next : graph[node]) {
					if (color[next - 1] > 0) continue;
					vector<bool> visited(4);
					for (int n : graph[next]) {
						if (color[n - 1] > 0) visited[color[n - 1] - 1] = true;
					}
					for (int i = 0; i < visited.size(); i++) {
						if (!visited[i]) {
							color[next - 1] = i + 1;
							q.push(next);
							break;
						}
					}
				}
			}
		}
		return color;
	}
};

int main() {

}