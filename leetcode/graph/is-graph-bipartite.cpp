#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/**
*  判断二分图：https://leetcode.cn/problems/is-graph-bipartite/
*
*  思路：并查集 + BFS
*		1.只需要并查集的思想，并查集的parent数组即可。
*		2.由于"这个图可能不是连通图"，所以要遍历所有可能的起点。
*/
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> parent(n, -2);
		//parent即可，不需要visited数组
		//vector<bool> visited(n);
		for (int i = 0; i < graph.size(); i++) {
			if (parent[i] != -2) continue;
			queue<int> q;
			q.push(i);
			parent[i] = 0;
			while (!q.empty()) {
				int start = q.front();
				q.pop();
				for (int end : graph[start]) {
					if (parent[end] == -2) {
						//0取反是-1，所以parent初始化的时候，用了-2
						parent[end] = !parent[start];
						q.push(end);
					}
					else {
						if (parent[end] == parent[start]) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}
};

int main() {
	Solution su;
	vector<vector<int>> graph{ {1, 3}, { 0, 2 }, { 1, 3}, { 0, 2} };
	su.isBipartite(graph);
	cout << !0 << endl;
}