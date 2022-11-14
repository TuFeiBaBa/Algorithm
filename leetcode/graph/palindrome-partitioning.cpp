#include <vector>
#include <string>
#include <iostream>

using namespace std;
//class Solution {
//private:
//	void dfs(vector<vector<bool>> dp, string s, int start, vector<vector<string>>& ans, vector<string> pStr) {
//		if (start >= s.size()) {
//			ans.push_back(pStr);
//			return;
//		}
//		/*for (int i = start; i < s.size(); i++) {
//			for (int len = 1; len <= s.size() - i; len++) {
//				if (dp[i][i + len - 1]) {
//					pStr.push_back(s.substr(i, len));
//					dfs(dp, s, i + len, ans, pStr);
//				}
//			}
//		}*/
//		for (int len = 1; len <= s.size() - start; len++) {
//			if (dp[start][start + len - 1]) {
//				pStr.push_back(s.substr(start, len));
//				dfs(dp, s, start + len, ans, pStr);
//				//["g","o","oo","g","l","e"]
//				pStr.pop_back();
//			}
//		}
//	}
//
//public:
//	vector<vector<string>> partition(string s) {
//		int n = s.size();
//		vector<vector<bool>> dp(n, vector<bool>(n));
//		vector<vector<string>> ans;
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = true;
//			//ans.push_back(s.substr(i, 1));
//		}
//		for (int i = 0; i < n - 1; i++) {
//			if (s[i] == s[i + 1]) {
//				dp[i][i + 1] = true;
//				//ans.push_back(s.substr(i, 2));
//			}
//		}
//		for (int d = 2; d < n; d++) {
//			for (int i = 0; i < n; i++) {
//				int j = d + i;
//				if (j >= n) continue;
//				if (dp[i + 1][j - 1] && s[i] == s[j]) {
//					dp[i][j] = true;
//					//ans.push_back(s.substr(i, d + 1));
//				}
//			}
//		}
//		/*for (int d = 0; d < n; d++) {
//			vector<string> strs;
//			for (int i = 0; i < n; i++) {
//				int j = d + i;
//				if (j >= n) continue;
//
//			}
//		}*/
//		dfs(dp, s, 0, ans, vector<string>());
//		return ans;
//	}
//};
/*
* 分割回文子字符串 https://leetcode.cn/problems/M99OJA/description/
*/
class Solution {
private:
	//相比上面注释的代码，使用成员变量，或者引用，能减少大量递归过程中的拷贝
	vector<vector<string>> ans;
	vector<vector<bool>> dp;
	vector<string> tmp;

private:
	void dfs(string& s, int start) {
		if (start >= s.size()) {
			ans.push_back(tmp);
			return;
		}
		for (int end = start; end < s.size(); end++) {
			if (dp[start][end]) {
				//substr的第一个参数是position，第二个参数是count
				tmp.push_back(s.substr(start, end - start + 1));
				dfs(s, end + 1);
				//回溯
				tmp.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		int n = s.size();
		//不应该加参数n，会创建一个有n个vector<string>空数组的vector<vector<string>>
		//每次ans.push_back是在此基础上追加
		//ans = vector<vector<string>>(n);
		ans = vector<vector<string>>();
		dp = vector<vector<bool>>(n, vector<bool>(n, true));

		//非常精妙的初始化，如果要求是求方案数，也是可以的(https://leetcode.cn/problems/palindromic-substrings/description/)。
		//int nums = n;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
				//if (dp[i][j]) nums++;
			}
		}

		//如果是Java的话，布尔数组初始化的时候，只能是false，所以稍微有点不同
		/*int res = 0;
		boolean[][] dp = new boolean[n][n];
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);
				if (dp[i][j]) ++res;
			}
		}*/

		dfs(s, 0);
		return ans;
	}
};

int main() {
	Solution su;
	su.partition("google");
}