#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//class Solution {
//public:
//	int minReorder(int n, vector<vector<int>>& connections) {
//		vector<vector<int>> graph(n, vector<int>(n, 0));
//		for (int i = 0; i < connections.size(); i++) {
//			graph[connections[i][0]][connections[i][1]] = 1;
//			graph[connections[i][1]][connections[i][0]] = 2;
//		}
//
//		queue<int> q;
//		vector<bool> used;
//		q.push(0);
//		int ans = 0;
//		while (!q.empty()) {
//			int top = q.front();
//			q.pop();
//			used[top] = true;
//			//�����⣺i�����Ƕ��㣬���Ǵ����Ƿ��top���������ߡ����߳���
//			for (int i : graph[top]) {
//				if (!graph[top][i] || used[i]) continue;
//				if (graph[top][i] == 1) ans++;
//				q.push(i);
//			}
//		}
//		return ans;
//	}
//};

/*
* ���¹滮·�� https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
* 
* ���鼯��
* �����ʡ����鼯���ŵ��ǿ��ٲ������ߵĹ�ϵ�����������ômerge��һ�����⡣0->1��2->1�����ֻҪ�޸�0->1�ķ���͹��ˡ��ò��鼯��
* ���ѱ��������������⡣
* 
* BFS:
* ����۲죬���֣���·�����γ�һ�������������Ƿ���Ļ�����Ȼ�ܴӽڵ�0�������κ��������㡣ֻҪ�ڱ��������У���¼�����������·�����ɡ�
*/
class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		//�õ�����ά�����Ƕ�ά
		//�о�������άҲ���ԣ���Ϊ����ͼ�õ����ڽӾ�����vector<Edge>���ɣ�Edge���������ͷ��򼴿ɡ�
		vector<vector<vector<int>>> graph(n);
		for (int i = 0; i < connections.size(); i++) {
			graph[connections[i][0]].emplace_back(vector<int>{ connections[i][1], 1 });
			graph[connections[i][1]].emplace_back(vector<int>{ connections[i][0], 2 });
		}

		queue<int> q;
		vector<bool> used(n);
		q.push(0);
		int ans = 0;
		while (!q.empty()) {
			int top = q.front();
			q.pop();
			used[top] = true;
			for (vector<int> v : graph[top]) {
				if (used[v[0]]) continue;
				if (v[1] == 1) ans++;
				q.push(v[0]);
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
	Solution su;
	int nums = su.minReorder(6, connections);
	cout << nums << endl;
}