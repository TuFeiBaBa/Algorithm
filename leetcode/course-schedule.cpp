#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool dfs(vector<vector<int>>& digraph, int course, vector<int>& visited) {
		//表示当前课程在栈中
		visited[course] = 1;
		for (int c : digraph[course]) {
			if (visited[c] == 1) return false;
			//剪枝
			if (visited[c] == 2) continue;
			bool b = dfs(digraph, c, visited);
			if (!b) return false;
		}
		//表示当前课程已经被检查过了，符合要求
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
		//遍历的原因：可能有多个起点
		for (int i = 0; i < digraph.size(); i++) {
			if (digraph[i].empty()) continue;
			//课程已经被检查过了
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