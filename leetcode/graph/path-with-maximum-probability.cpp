#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
* 概率最大的路径 https://leetcode.cn/problems/path-with-maximum-probability/
* 
* 求概率最大的路径，即是求最长路径。可以用Dijkstra算法来求解(Dijkstra算法虽然是求单源最短路径，但是调整代码后，很容易变成求单源最长路径)。
* 另外，注意该图是无向图。
*/
class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<vector<pair<double, int>>> graph(n);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
			graph[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
		}

		vector<double> dict(n, 0);
		vector<bool> used(n);
		priority_queue<pair<double, int>> q;
		//起点的概率为1
		dict[start] = 1;
		q.emplace(1, start);
		while (!q.empty()) {
			auto& top = q.top();
			double d = top.first;
			int n = top.second;
			used[n] = true;
			q.pop();
			if (d < dict[n]) continue;
			for (auto& p : graph[n]) {
				double y = p.first;
				int node = p.second;
				//因为是无向图，所以肯定有重复，不过used数组不用也行，dict[node] < ny其实能起到类似的效果
				if (used[node]) continue;
				double ny = d * y;
				if (dict[node] < ny) {
					dict[node] = ny;
					q.emplace(ny, node);
				}
			}
		}
		return dict[end];
	}
};

int main() {
	vector<vector<int>> edges = { {0, 1},{1, 2},{0, 2} };
	vector<double> succProb = { 0.5,0.5,0.2 };
	Solution su;
	double ans = su.maxProbability(3, edges, succProb, 0, 2);
	cout << ans << endl;
}