#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
* 想得过于复杂了。想用模拟来做，没有成功。
* 1)边长都是一样的，用BFS可以轻松算出dis。
* 2)漏了一点：客户端一旦收到消息，就不会再尝试发送
*/
//class Solution {
//public:
//	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
//		int n = patience.size();
//		vector<vector<pair<int, int>>> g(n);
//		for (int i = 0; i < edges.size(); i++) {
//			g[edges[i][0]].emplace_back(edges[i][1], 2);
//			g[edges[i][1]].emplace_back(edges[i][0], 2);
//		}
//		vector<int> dis(n, INT_MAX); dis[0] = 0;
//		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//		pq.emplace(0, 0);
//		while (!pq.empty()) {
//			auto [d, from] = pq.top();
//			pq.pop();
//			if (d > dis[from]) continue;
//			for (auto& [to, side] : g[from]) {
//				int dt = d + side;
//				if (dt < dis[to]) {
//					dis[to] = dt;
//					pq.emplace(dt, to);
//				}
//			}
//		}
//
//		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> tasks;
//		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//		for (int i = 1; i < n; i++) {
//			tasks.emplace(dis[i], i);
//			q.emplace(patience[i], i);
//		}
//		int ans = 0;
//		vector<bool> arrived(n);
//		while (true) {
//			int time =  (!q.empty())? q.top().first : INT_MAX;
//			//auto& [time, i] = q.top();
//			while (!tasks.empty() && tasks.top().first <= time) {
//				auto [cur, j] = tasks.top();
//				tasks.pop();
//				arrived[j] = true;
//				ans = cur + 1;
//			}
//			if (tasks.empty()) {
//				return ans;
//			}
//			while (!q.empty() && q.top().first < tasks.top().first) {
//				auto [cur, j] = tasks.top();
//				auto [recent, k] = q.top();
//				q.pop();
//				tasks.emplace(recent + dis[k] - 1, k);
//				if(!arrived[k]) q.emplace(recent + patience[k], k);
//			}
//		}
//		return ans;
//	}
//};


/*
* 网络空闲的时刻 https://leetcode.cn/problems/the-time-when-the-network-becomes-idle/description/
*/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (auto& v : edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                int curr = qu.front();
                qu.pop();
                for (auto& v : adj[curr]) {
                    if (visit[v]) {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};

int main() {
	vector<vector<int>> edges = { {0, 1},{1, 2} };
	vector<int> patience = { 0, 2, 1 };
	Solution su;
	int ans = su.networkBecomesIdle(edges, patience);
	cout << ans << endl;
}