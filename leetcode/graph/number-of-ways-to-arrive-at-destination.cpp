#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
* 到达目的地的方案数 https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/description/
* 
* 单源最短路径。但要求满足0->n - 1的最短路径的所有路径数目，就要想办法把计算写在dijkstr算法的模板代码里面。
*	1)dt == dis[to]，路径数 + 1
*	2)from == n - 1时，直接返回记录的路径数
* 
* 忽略的点：想用一个int值：num来记录路径数，忽略了这其实是个dp问题。
*/
class Solution {
public:
	int countPaths(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, long>>> g(n);
		for (int i = 0; i < roads.size(); i++) {
			g[roads[i][0]].emplace_back(roads[i][1], roads[i][2]);
			g[roads[i][1]].emplace_back(roads[i][0], roads[i][2]);
		}
		int mod = 1e9 + 7;
		vector<long> dis(n, LONG_MAX); dis[0] = 0;
		vector<int> dp(n, 0); dp[1] = 1;
		priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq; pq.emplace(0, 0);
		while (!pq.empty())
		{
			auto [d, from] = pq.top(); pq.pop();
			if (d > dis[from]) continue;
			if (from == n - 1) {
				return dp[n - 1];
			}
			for (auto& [to, side] : g[from]) {
				//int会因为溢出导致错误
				//int dt = d + side;
				long dt = d + side;
				if (dt < dis[to]) {
					dp[to] = dp[from];
					dis[to] = dt;
					pq.emplace(dt, to);
				}
				else if (dt == dis[to]) {
					dp[to] = (dp[to] + dp[from]) % mod;
				}
			}
		}
		return dp[n - 1];
	}
};

int main() {
	vector<vector<int>> roads = { {0, 6, 7},{0, 1, 2},{1, 2, 3},{1, 3, 3},{6, 3, 3},{3, 5, 1},{6, 5, 1},{2, 5, 1},{0, 4, 5},{4, 6, 2} };
	Solution su;
	int num = su.countPaths(7, roads);
	cout << num << endl;
}