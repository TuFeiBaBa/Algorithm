#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
	// 解法一：暴力。时间复杂度O(n ^ 2)
//	bool dfs(string s, string goal, int m,int n) {
//		if (m > s.size()) return false;
//		if (n > goal.size()) return true;
//		if (s[m] != goal[n]) return false;
//		return dfs(s, goal, m + 1, n + 1);
//	}
//
//	bool rotateString(string s, string goal) {
//		//陷阱：s和goal必须长度一致
//		if (s.size() != goal.size()) return false;
//		s = s + s;
//		for (int i = 0; i < s.size() - goal.size(); i++) {
//			int res = dfs(s, goal, i, 0);
//			if (res) return true;
//		}
//		return false;
//	}

	void buildNext(vector<int>& next, string& goal) {
		int i = 1;
		int k = 0;
		while (i < goal.size()) {
			if (goal[k] == goal[i]) {
				next[i] = k + 1;
				i++;
				k++;
			}
			else if (k != 0) {
				k = next[k - 1];
			}
			else {
				i++;
			}
		}
	}

	//解法二：KMP
	bool rotateString(string s, string goal) {
		if (s.size() != goal.size()) return false;
		s = s + s;
		vector<int> next(goal.size(), 0);
		buildNext(next, goal);

		int s_pos = 0;
		int pos = 0;
		while (s_pos < s.size()) {
			if (s[s_pos] == goal[pos]) {
				s_pos++;
				pos++;
			}
			else if (pos != 0) {
				pos = next[pos - 1];
			}
			else {
				s_pos++;
			}
			if (pos == goal.size()) {
				cout << "goal begin index :" << s_pos - pos << endl;
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution su;
	assert(su.rotateString("abcde", "cdeab"));
	assert(!su.rotateString("abcde", "abced"));
}