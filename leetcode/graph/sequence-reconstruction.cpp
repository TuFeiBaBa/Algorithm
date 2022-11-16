#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
/*
* �ؽ����� https://leetcode.cn/problems/ur2n8P/description/
* 
* ˼·��https://leetcode.cn/problems/ur2n8P/solutions/1973838/bfsfei-tuo-bu-pan-duan-shi-fou-neng-cong-ivfg/?orderBy=newest_to_oldest
* 
* ����������ʵҲ�ǿ��Եģ�ֻ����������Ӷ�һ���жϣ�������Ľڵ��������ܴ���1��
* �ο���https://leetcode.cn/problems/ur2n8P/solutions/1688770/zhong-jian-xu-lie-by-leetcode-solution-urxc/
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
			//�ִ�nums[nums.size() - 1]
			if (cur == nums[n - 1]) return true;
			//�ж��ڽӵ��Ƿ���nums[idx + 1]
			if (g[cur].find(idx + 1) != g[cur].end()) q.push(nums[++idx]);
		}
		//�޷��ִ�nums[nums.size() - 1]
		return false;
	}
};

int main() {

}