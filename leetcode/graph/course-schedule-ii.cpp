#include <vector>
#include <iostream>
#include <algorithm>
#include <xutility>
using namespace std;

/**
 * �γ̱� II https://leetcode-cn.com/problems/course-schedule-ii/
 * ���ⲽ�裺
 * 1.��ͼ
 * 2.����ͼ
 *	1.onStack�ж��Ƿ��л�
 *  2.visited�ж��Ƿ��Ѿ����ʹ������ڼ�֦
 *  3.����������������Ҳ�Ƿ���Ҫ��Ŀγ̰���˳��
 */
class Solution {
private:
	vector<vector<int>> graph;
	vector<int> paths;
	vector<int> visited;

	bool dfs(int course) {
		visited[course] = 1;
		//ǰ���ǲ��е�
		//paths.push_back(course);
		for (int c : graph[course]) {
			if (visited[c] == 1) return false;
			if (visited[c] == 2) continue;
			if (!dfs(c)) return false;
		}
		visited[course] = 2;
		//�����Ǻ���������������������ս�����÷�תһ�¡�
		paths.push_back(course);
		return true;
	}

public:

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		graph = vector<vector<int>>(numCourses);
		//paths = vector<int>(numCourses)�Ǵ���ġ���Ҫ��Java��д..
		paths = vector<int>();
		visited = vector<int>(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < numCourses; i++) {
			//if(visited[i])Ҳ�У�visited[i]Ϊ1ʱ��dfs�϶��Ѿ����ֻ����˳������ˡ�
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