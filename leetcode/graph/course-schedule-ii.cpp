#include <vector>
#include <iostream>
#include <algorithm>
#include <xutility>
using namespace std;

/**
 * 课程表 II https://leetcode-cn.com/problems/course-schedule-ii/
 * 解题步骤：
 * 1.建图
 * 2.遍历图
 *	1.onStack判断是否有环
 *  2.visited判断是否已经访问过，用于剪枝
 *  3.逆后序就是拓扑排序，也是符合要求的课程安排顺序
 */
class Solution {
private:
	vector<vector<int>> graph;
	vector<int> paths;
	vector<int> visited;

	bool dfs(int course) {
		visited[course] = 1;
		//前序是不行的
		//paths.push_back(course);
		for (int c : graph[course]) {
			if (visited[c] == 1) return false;
			if (visited[c] == 2) continue;
			if (!dfs(c)) return false;
		}
		visited[course] = 2;
		//这里是后序，拓扑排序是逆后序。最终结果还得翻转一下。
		paths.push_back(course);
		return true;
	}

public:

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		graph = vector<vector<int>>(numCourses);
		//paths = vector<int>(numCourses)是错误的。不要当Java来写..
		paths = vector<int>();
		visited = vector<int>(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < numCourses; i++) {
			//if(visited[i])也行：visited[i]为1时，dfs肯定已经发现环，退出遍历了。
			if (visited[i] == 2) continue;
			if (!dfs(i)) {
				return vector<int>();
			}
		}
		reverse(paths.begin(), paths.end());
		return paths;
	}
};

int main() {
	Solution su;
	vector<vector<int>> prerequisites{ {1, 0}, { 0, 1 } };
	vector<int> order = su.findOrder(2, prerequisites);
	std::for_each(order.begin(), order.end(), [](const auto& i) {std::cout << i << " "; });
}