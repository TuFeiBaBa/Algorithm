#include <vector>
#include <iostream>
using namespace std;
/*
* 解题思路：
* 1.构建图：有向图，用vector<int>
* 2.遍历图：
*	1.是否有环：onStack数组
*	2.遍历过程中的剪枝：visited数组
*	两者可以考虑合并，onStack用1来表示。visited用2来表示
* 3.遍历图时，要外层大循环检查所有的顶点，因为它不一定是树结构，只有一个入口。
*/
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