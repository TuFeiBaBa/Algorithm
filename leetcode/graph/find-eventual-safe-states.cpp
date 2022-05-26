#include <vector>
#include <queue>
using namespace std;
/**
* 找到最终的安全状态：https://leetcode.cn/problems/find-eventual-safe-states/
*
* 核心思路：
* 若一个节点没有出边，则该节点是安全的；若一个节点出边相连的点都是安全的，则该节点也是安全的。
* 根据这一性质，我们可以将图中所有边反向，得到一个反图，然后在反图上运行拓扑排序。
*
*/
class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> g(n);
		vector<int> in(n);
		for (int i = 0; i < n; i++) {
			for (int j : graph[i]) {
				g[j].push_back(i);
				in[i]++;
			}
		}
		queue<int> q;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				q.push(i);
				ans.push_back(i);
			}
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : g[x]) {
				in[y]--;
				if (in[y] == 0) {
					q.push(y);
					ans.push_back(y);
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};


int main() {

}