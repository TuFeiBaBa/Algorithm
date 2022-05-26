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
class Solution {
private:
	vector<vector<vector<int>>> mem;
	vector<bool> visited;

	vector<vector<int>> dfs(vector<vector<int>>& graph, int x) {
		if (visited[x]) {
			return mem[x];
		}
		visited[x] = true;
		//д����һ��=
		if (x == graph.size() - 1) {
			mem[x].emplace_back(vector<int>{x});
			return mem[x];
		}
		for (int y : graph[x]) {
			vector<vector<int>> ans = dfs(graph, y);
			if (!ans.empty()) {
				for (auto& vec : ans) {
					vector<int> copy(vec);
					copy.emplace_back(x);
					mem[x].emplace_back(copy);
				}
			}
		}
		return mem[x];
	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		visited = vector<bool>(graph.size());
		mem = vector<vector<vector<int>>>(graph.size());
		dfs(graph, 0);
		//&����©����Ȼreverse��������
		for (vector<int>& vec : mem[0]) {
			reverse(vec.begin(), vec.end());
		}
		return mem[0];
	}
};

int main() {
	vector<vector<int>> graph{ {1,2 }, { 3 }, { 3 }, {} };
	Solution su;
	su.allPathsSourceTarget(graph);
}