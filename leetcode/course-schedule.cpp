#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool dfs(vector<vector<int>>& digraph, int course, vector<int>& visited) {
		//��ʾ��ǰ�γ���ջ��
		visited[course] = 1;
		for (int c : digraph[course]) {
			if (visited[c] == 1) return false;
			//��֦
			if (visited[c] == 2) continue;
			bool b = dfs(digraph, c, visited);
			if (!b) return false;
		}
		//��ʾ��ǰ�γ��Ѿ��������ˣ�����Ҫ��
		visited[course] = 2;
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.size() == 0) return true;
		vector<vector<int>> digraph(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			digraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		vector<int> visited(numCourses);
		for (int i = 0; i < digraph.size(); i++) {
			if (digraph[i].empty()) continue;
			//�γ��Ѿ���������
			if (visited[i]) continue;
			bool b = dfs(digraph, i, visited);
			if (!b) return false;
		}
		return true;
	}
};

int main() {
	Solution su;
	vector<vector<int>> prerequisites{ {1,0},{0,1} };
	bool ret = su.canFinish(2, prerequisites);
	cout << ret << endl;
}