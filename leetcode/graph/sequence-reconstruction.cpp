#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
/*
* 重建序列 https://leetcode.cn/problems/ur2n8P/description/
* 
* 思路：https://leetcode.cn/problems/ur2n8P/solutions/1973838/bfsfei-tuo-bu-pan-duan-shi-fou-neng-cong-ivfg/?orderBy=newest_to_oldest
* 
* 拓扑排序其实也是可以的，只是拓扑排序加多一个判断：队列里的节点数，不能大于1，
* 参考：https://leetcode.cn/problems/ur2n8P/solutions/1688770/zhong-jian-xu-lie-by-leetcode-solution-urxc/
*/
class Solution {
public:
	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
		/*int n = nums.size();
		unordered_map<int, vector<int>> g(n);
		for (int i = 0; i < sequences.size(); i++) {
			for (int j = 0; j < sequences[i].size() - 1; j++) {
				g[sequences[i][j]].push_back(sequences[i][j + 1]);
			}
		}
		queue<int> q;
		q.push(nums[0]);
		int idx = 0;
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			if (n == nums[nums.size() - 1]) return true;
			for (int next : g[n]) {
				if (next == nums[idx + 1]) {
					q.push(next);
					idx++;
					break;
				}
			}
		}*/

		int n = nums.size();
		unordered_map<int, unordered_set<int>> g(n);
		for (int i = 0; i < sequences.size(); i++) {
			for (int j = 0; j < sequences[i].size() - 1; j++) {
				g[sequences[i][j]].insert(sequences[i][j + 1]);
			}
		}
		queue<int> q;
		q.push(nums[0]);
		int idx = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			//抵达nums[nums.size() - 1]
			if (cur == nums[n - 1]) return true;
			//判断邻接点是否有nums[idx + 1]
			if (g[cur].find(idx + 1) != g[cur].end()) q.push(nums[++idx]);
		}
		//无法抵达nums[nums.size() - 1]
		return false;
	}
};

int main() {

}