#include <vector>
using namespace std;
/*
* 课程表 IV https://leetcode.cn/problems/course-schedule-iv/
*/
class Solution {

	/*
	* 并查集：
	* 不适合此题：
	* 1.课程a、b、c，a -> b -> c、a-> c && b-> c是不同的情况。显然不能使用路径压缩
	* 2.并查集处理后，如果是a -> b -> c的话，查[a,c]，显然得搜索整条路径才能知道，无法在O(1)时间复杂度内完成
	*/

	//private:
	//	vector<int> parent;
	//	vector<int> weight;
	//
	//	int find(int x) {
	//		if (parent[x] != x) {
	//			parent[x] = find(parent[x]);
	//		}
	//		return parent[x];
	//	}
	//
	//	void merge(int x, int y) {
	//		int rootX = find(x);
	//		int rootY = find(y);
	//		if (rootX == rootY) return;
	//		if (weight[rootX] > weight[rootY]) {
	//			weight[rootX] += weight[rootY];
	//			parent[rootY] = rootX;
	//		}
	//		else {
	//			weight[rootY] += weight[rootX];
	//			parent[rootX] = rootY;
	//		}
	//	}
	//
	//public:
	//	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	//		weight = vector<int>(numCourses, 1);
	//		parent = vector<int>(numCourses);
	//		for (int i = 0; i < numCourses; i++) {
	//			parent[i] = i;
	//		}
	//
	//		for (auto& p : prerequisites) {
	//			merge(p[0], p[1]);
	//		}
	//
	//		vector<bool> ans(queries.size());
	//		for (int i = 0; i < queries.size(); i++) {
	//			ans[i] = find(queries[i][0]) != find(queries[i][1]);
	//		}
	//
	//		return ans;
	//	}

public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		/*vector<vector<int>> graph(numCourses, vector<int>(numCourses,10000));
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[i][i] = 0;
			graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
		}
		for (int k = 0; k < numCourses; k++) {
			for (int i = 0; i < numCourses; i++) {
				for (int j = 0; j < numCourses; j++) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		};*/
		vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
		}
		for (int k = 0; k < numCourses; k++) {
			for (int i = 0; i < numCourses; i++) {
				for (int j = 0; j < numCourses; j++) {
					//路径长度在这里意义不大，需要对Floyd算法做一点小小的变更
					//graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					if (graph[i][k] && graph[k][j]) graph[i][j] = 1;
					//效果等同于下
					//graph[i][j] = graph[i][j] | graph[i][k] & graph[k][j];
				}
			}
		};

		vector<bool> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			ans[i] = graph[queries[i][0]][queries[i][1]] == 1;
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> prerequisites = { {1,0} };
	vector<vector<int>> queries = { {0,1},{1,0} };
	Solution su;
	su.checkIfPrerequisite(2, prerequisites, queries);
	return 0;
}