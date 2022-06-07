#include <string>
#include <vector>
using namespace std;
/*
* 错误思路：
*
* 求的是最长回文，不是求长度。而且dp[i + 1][j - 1]可能不是回文，那就更没有意义了
* dp[i][j] = if(s[i] == s[j]) dp[i + 1][j - 1] + 2 else max(dp[i][j],dp[i + 1][j],dp[i][j - 1])
*/
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int n = s.size();
//		vector<vector<int>> dp(n, vector<int>(n));
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = 1;
//			//dp[i][i + 1]也要进行初始化
//			if (i + 1 < n) dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 0;
//		}
//
//		int maxLen = 0;
//		for (int d = 2; d < n; d++) {
//			for (int i = 0; i < n - d; i++) {
//				//j等于i + d，不应该再进行for循环
//				for (int j = i + d; j < n; j++) {
//					//求的是最长回文，不是求长度。而且dp[i + 1][j - 1]可能不是回文，那就更没有意义了
//					if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
//					else {
//						dp[i][j] = max(dp[i][j], dp[i + 1][j]);
//						dp[i][j] = max(dp[i][j], dp[i][j + 1]);
//					}
//				}
//			}
//		}
//	}
//};

/*
* 最长回文子串：https://leetcode.cn/problems/longest-palindromic-substring/
*
* 注意事项：
*   1.回文有两种：①以某个字符为中心，②以某两个相等的字符(或者说以空字符)为中心
*   2.这里求的是最长回文子串，不是求长度。不过不应该在推导过程中不停切割字符串。
*	  可以在推导过程中，不断判断是否是最长的回文，不断更新最长回文的start_pos和end_pos。最后再进行切割。
*
* 最优解是Manacher算法：https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
*/
class Solution {
public:
	string longestPalindrome(string s) {

	}
};

int main() {

}