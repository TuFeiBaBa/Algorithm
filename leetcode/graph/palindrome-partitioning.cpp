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
* �ָ�������ַ��� https://leetcode.cn/problems/M99OJA/description/
*/
class Solution {
private:
	//�������ע�͵Ĵ��룬ʹ�ó�Ա�������������ã��ܼ��ٴ����ݹ�����еĿ���
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
				//substr�ĵ�һ��������position���ڶ���������count
				tmp.push_back(s.substr(start, end - start + 1));
				dfs(s, end + 1);
				//����
				tmp.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		int n = s.size();
		//��Ӧ�üӲ���n���ᴴ��һ����n��vector<string>�������vector<vector<string>>
		//ÿ��ans.push_back���ڴ˻�����׷��
		//ans = vector<vector<string>>(n);
		ans = vector<vector<string>>();
		dp = vector<vector<bool>>(n, vector<bool>(n, true));

		//�ǳ�����ĳ�ʼ�������Ҫ�����󷽰�����Ҳ�ǿ��Ե�(https://leetcode.cn/problems/palindromic-substrings/description/)��
		//int nums = n;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
				//if (dp[i][j]) nums++;
			}
		}

		//�����Java�Ļ������������ʼ����ʱ��ֻ����false��������΢�е㲻ͬ
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