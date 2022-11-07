#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
/*
* 有向无环图中一个节点的所有祖先 https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
*/
class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		vector<int> in(n);
		for (int i = 0; i < edges.size(); i++) {
			g[edges[i][0]].emplace_back(edges[i][1]);
			in[edges[i][1]]++;
		}
		vector<set<int>> record(n);
		vector<vector<int>> ans(n);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int from = q.front();
			q.pop();
			for (int to : g[from]) {
				in[to]--;
				for (int node : record[from]) {
					record[to].insert(node);
				}
				record[to].insert(from);
				if (in[to] == 0) q.push(to);
			}
		}
		for (int i = 0; i < n; i++) {
			set<int> s = record[i];
			vector<int> v(s.size());
			copy(s.begin(), s.end(), v.begin());
			sort(v.begin(), v.end());
			ans[i] = v;
		}

		//下列方法也可以
		/*for (int i = 0; i < n; i++) {
			for (int j : record[i]) {
				ans[i].push_back(j);
			}
			sort(ans[i].begin(), ans[i].end());
		}*/
		return ans;
	}
};

int main() {
	vector<vector<int>> edges = { {0, 3}, { 0, 4 }, { 1, 3}, { 2, 4 }, { 2, 7 }, { 3, 5 }, { 3, 6}, { 3, 7}, { 4, 6} };
	Solution su;
	su.getAncestors(8, edges);
}