#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/**
*  �ж϶���ͼ��https://leetcode.cn/problems/is-graph-bipartite/
*
*  ˼·�����鼯 + BFS
*		1.ֻ��Ҫ���鼯��˼�룬���鼯��parent���鼴�ɡ�
*		2.����"���ͼ���ܲ�����ͨͼ"������Ҫ�������п��ܵ���㡣
*/
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> parent(n, -2);
		//parent���ɣ�����Ҫvisited����
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
						//0ȡ����-1������parent��ʼ����ʱ������-2
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