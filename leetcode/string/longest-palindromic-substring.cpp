#include <string>
#include <vector>
using namespace std;
/*
* ����˼·��
*
* ���������ģ������󳤶ȡ�����dp[i + 1][j - 1]���ܲ��ǻ��ģ��Ǿ͸�û��������
* dp[i][j] = if(s[i] == s[j]) dp[i + 1][j - 1] + 2 else max(dp[i][j],dp[i + 1][j],dp[i][j - 1])
*/
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int n = s.size();
//		vector<vector<int>> dp(n, vector<int>(n));
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = 1;
//			//dp[i][i + 1]ҲҪ���г�ʼ��
//			if (i + 1 < n) dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 0;
//		}
//
//		int maxLen = 0;
//		for (int d = 2; d < n; d++) {
//			for (int i = 0; i < n - d; i++) {
//				//j����i + d����Ӧ���ٽ���forѭ��
//				for (int j = i + d; j < n; j++) {
//					//���������ģ������󳤶ȡ�����dp[i + 1][j - 1]���ܲ��ǻ��ģ��Ǿ͸�û��������
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
* ������Ӵ���https://leetcode.cn/problems/longest-palindromic-substring/
*
* ע�����
*   1.���������֣�����ĳ���ַ�Ϊ���ģ�����ĳ������ȵ��ַ�(����˵�Կ��ַ�)Ϊ����
*   2.���������������Ӵ��������󳤶ȡ�������Ӧ�����Ƶ������в�ͣ�и��ַ�����
*	  �������Ƶ������У������ж��Ƿ�����Ļ��ģ����ϸ�������ĵ�start_pos��end_pos������ٽ����и
*
* ���Ž���Manacher�㷨��https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
*/
class Solution {
public:
	string longestPalindrome(string s) {

	}
};

int main() {

}