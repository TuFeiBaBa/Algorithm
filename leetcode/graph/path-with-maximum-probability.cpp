#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
* ��������·�� https://leetcode.cn/problems/path-with-maximum-probability/
* 
* ���������·�����������·����������Dijkstra�㷨�����(Dijkstra�㷨��Ȼ����Դ���·�������ǵ�������󣬺����ױ����Դ�·��)��
* ���⣬ע���ͼ������ͼ��
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
		//���ĸ���Ϊ1
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
				//��Ϊ������ͼ�����Կ϶����ظ�������used���鲻��Ҳ�У�dict[node] < ny��ʵ�������Ƶ�Ч��
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