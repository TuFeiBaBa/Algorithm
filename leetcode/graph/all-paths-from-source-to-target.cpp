#include <vector>
using namespace std;
/**
* 所有可能的路径：https://leetcode.cn/problems/all-paths-from-source-to-target/
* 思路：dfs + 记忆优化
* 问题点：AC了，但是耗时较长。2 <= n <= 15，记忆优化能起的作用是有限的。
*		  反而是大量得创建数组、拷贝元素，拖慢了整体耗时。
*
* 回溯：
*	图是DAG，即有向无环，所以，在一条路径里，不会重复经过一个点（但多条路径其实是会的）。
*	一般题干中出现 all possible关键字，都可以考虑用 backtracking 算法。
*/
//class Solution {
//private:
//	vector<vector<vector<int>>> mem;
//	vector<bool> visited;
//
//	vector<vector<int>> dfs(vector<vector<int>>& graph, int x) {
//		if (visited[x]) {
//			return mem[x];
//		}
//		visited[x] = true;
//		//写少了一个=
//		if (x == graph.size() - 1) {
//			mem[x].emplace_back(vector<int>{x});
//			return mem[x];
//		}
//		for (int y : graph[x]) {
//			vector<vector<int>> ans = dfs(graph, y);
//			if (!ans.empty()) {
//				for (auto& vec : ans) {
//					vector<int> copy(vec);
//					copy.emplace_back(x);
//					mem[x].emplace_back(copy);
//				}
//			}
//		}
//		return mem[x];
//	}
//
//public:
//	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//		visited = vector<bool>(graph.size());
//		mem = vector<vector<vector<int>>>(graph.size());
//		dfs(graph, 0);
//		//&不能漏，不然reverse不起作用
//		for (vector<int>& vec : mem[0]) {
//			reverse(vec.begin(), vec.end());
//		}
//		return mem[0];
//	}
//};

class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;

	void dfs(vector<vector<int>>& graph, int node) {
		if (node == graph.size() - 1) {
			//不需要额外创建，C++默认是拷贝的
			//ans.push_back(vector<int>(path));
			ans.push_back(path);
			return;
		}

		for (int& next : graph[node]) {
			path.push_back(next);
			dfs(graph, next);
			//也可以
			//path.erase(path.end() - 1);
			path.pop_back();
		}
	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		path.push_back(0);
		dfs(graph, 0);
		return ans;
	}
};

int main() {
	vector<vector<int>> graph{ {1,2 }, { 3 }, { 3 }, {} };
	Solution su;
	su.allPathsSourceTarget(graph);
}