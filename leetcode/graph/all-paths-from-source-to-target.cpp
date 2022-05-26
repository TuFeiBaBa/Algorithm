#include <vector>
using namespace std;
/**
* ���п��ܵ�·����https://leetcode.cn/problems/all-paths-from-source-to-target/
* ˼·��dfs + �����Ż�
* ����㣺AC�ˣ����Ǻ�ʱ�ϳ���2 <= n <= 15�������Ż���������������޵ġ�
*		  �����Ǵ����ô������顢����Ԫ�أ������������ʱ��
*
* ���ݣ�
*	ͼ��DAG���������޻������ԣ���һ��·��������ظ�����һ���㣨������·����ʵ�ǻ�ģ���
*	һ������г��� all possible�ؼ��֣������Կ����� backtracking �㷨��
*/
//class Solution {
//private:
//	vector<vector<vector<int>>> mem;
//	vector<bool> visited;
//
//	vector<vector<int>> dfs(vector<vector<int>>& graph, int x) {
//		if (visited[x]) {
//			return mem[x];
//		}
//		visited[x] = true;
//		//д����һ��=
//		if (x == graph.size() - 1) {
//			mem[x].emplace_back(vector<int>{x});
//			return mem[x];
//		}
//		for (int y : graph[x]) {
//			vector<vector<int>> ans = dfs(graph, y);
//			if (!ans.empty()) {
//				for (auto& vec : ans) {
//					vector<int> copy(vec);
//					copy.emplace_back(x);
//					mem[x].emplace_back(copy);
//				}
//			}
//		}
//		return mem[x];
//	}
//
//public:
//	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//		visited = vector<bool>(graph.size());
//		mem = vector<vector<vector<int>>>(graph.size());
//		dfs(graph, 0);
//		//&����©����Ȼreverse��������
//		for (vector<int>& vec : mem[0]) {
//			reverse(vec.begin(), vec.end());
//		}
//		return mem[0];
//	}
//};

class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;

	void dfs(vector<vector<int>>& graph, int node) {
		if (node == graph.size() - 1) {
			//����Ҫ���ⴴ����C++Ĭ���ǿ�����
			//ans.push_back(vector<int>(path));
			ans.push_back(path);
			return;
		}

		for (int& next : graph[node]) {
			path.push_back(next);
			dfs(graph, next);
			//Ҳ����
			//path.erase(path.end() - 1);
			path.pop_back();
		}
	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		path.push_back(0);
		dfs(graph, 0);
		return ans;
	}
};

int main() {
	vector<vector<int>> graph{ {1,2 }, { 3 }, { 3 }, {} };
	Solution su;
	su.allPathsSourceTarget(graph);
}