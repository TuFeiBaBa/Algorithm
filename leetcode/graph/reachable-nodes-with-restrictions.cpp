#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
/*
* ���������¿ɵ���ڵ����Ŀ https://leetcode.cn/problems/reachable-nodes-with-restrictions/description/
*/
class Solution {
public:
	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
		vector<vector<int>> g(n);
		//����Ҫ�����set��ֻҪused[restricted{i]] = true���ɡ�
		unordered_set<int> restr;

		for (int i = 0; i < edges.size(); i++) {
			g[edges[i][0]].emplace_back(edges[i][1]);
			g[edges[i][1]].emplace_back(edges[i][0]);
		}
		for (int i : restricted) {
			restr.insert(i);
		}

		int nums = 1;
		queue<int> q;
		q.push(0);
		vector<bool> used(n);
		used[0] = true;
		while (!q.empty()) {
			int from = q.front();
			q.pop();
			for (int to : g[from]) {
				if (used[to] || restr.find(to) != restr.end()) continue;
				used[to] = true;
				nums++;
				q.push(to);
			}
		}
		return nums;
	}
};

int main() {

}