#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
/**
* 从第一个节点出发到最后一个节点的受限路径数 https://leetcode.cn/problems/number-of-restricted-paths-from-first-to-last-node/description/
*/
class Solution {

private:
	int dfs(int n, vector<vector<pair<int, int>>>& graph, int node, vector<int> dict) {
		if (node == n) {
			return 1;
		}
		int nums = 0;
		for (auto& p : graph[node]) {
			int x = p.second;
			//不需要判断：x > node
			if (dict[x] < dict[node]) nums += dfs(n, graph, x, dict);
		}
		return nums;
	}

	static bool comp(pair<int, int>& p1, pair<int, int>& p2) {
		return p1.second < p2.second;
	}

public:
	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		vector<vector<pair<int, int>>> graph(n + 1);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].emplace_back(edges[i][2], edges[i][1]);
			graph[edges[i][1]].emplace_back(edges[i][2], edges[i][0]);
		}
		/*vector<bool> used(n + 1);
		queue<int> q;
		q.push(1);
		int ans = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			used[n] = true;
			for (int y : graph[x]) {
				if (y == n) {
					ans++;
				}
				else if (!used[y]) {
					q.push()
				}
			}
		}*/
		vector<int> dist(n + 1, INT_MAX);
		dist[n] = 0;
		priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> q;
		q.emplace(0, n);
		while (!q.empty()) {
			auto& p = q.top();
			int d = p.first;
			int x = p.second;
			q.pop();
			if (d > dist[x]) continue;
			for (auto& pair : graph[x]) {
				int dy = pair.first + d;
				int y = pair.second;
				if (dy < dist[y]) {
					dist[y] = dy;
					q.emplace(dy, y);
				}
			}
		}

		//return dfs(n, graph, 1, dist);


		//vector<pair<int, int>> paths;
		//for (int i = 0; i < n; i++) paths.emplace_back(i + 1, dist[i + 1]);
		//sort(paths.begin(), paths.end(), comp);
		//vector<int> dp(n + 1);
		//dp[n] = 1;
		//for (int i = 0; i < n; i++) {
		//	int idx = paths[i].first;
		//	int d = paths[i].second;
		//	for (auto& p : graph[idx]) {
		//		int next = p.second;
		//		if (d < dist[next]) {
		//			dp[next] += dp[idx];
		//		}
		//		/*if (d > dist[next]) {
		//			dp[idx] += dp[next];
		//		}*/
		//	}
		//	if (idx == 1) break;
		//}
		//return dp[1];

		int mod = 1e9 + 7;
		vector<int> index(n), dp(n + 1,0);
		iota(index.begin(), index.end(), 1);
		sort(index.begin(), index.end(), [&](auto a, auto b) {
			return dist[a] > dist[b];
			});
		dp[1] = 1;
		for (auto& from : index) {
			for (auto& [_, to] : graph[from]) {
				if (dist[to] < dist[from]) {
					dp[to] = (dp[to] + dp[from]) % mod;
				}
			}
		}
		return dp[n];
	}
};

int main() {
	vector<vector<int>> edges = { {1, 2, 3},{1, 3, 3},{2, 3, 1},{1, 4, 2},{5, 2, 2},{3, 5, 1},{5, 4, 10} };
	Solution su;
	int num = su.countRestrictedPaths(5, edges);
	cout << num << endl;
}