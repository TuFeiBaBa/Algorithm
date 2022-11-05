#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
* ����Ŀ�ĵصķ����� https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/description/
* 
* ��Դ���·������Ҫ������0->n - 1�����·��������·����Ŀ����Ҫ��취�Ѽ���д��dijkstr�㷨��ģ��������档
*	1)dt == dis[to]��·���� + 1
*	2)from == n - 1ʱ��ֱ�ӷ��ؼ�¼��·����
* 
* ���Եĵ㣺����һ��intֵ��num����¼·����������������ʵ�Ǹ�dp���⡣
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
				//int����Ϊ������´���
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