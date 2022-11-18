#include <string>
#include <vector>
#include <iostream>
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
//class Solution {
//private:
//	int findLongest(string& s, int start, int end) {
//		int len = 0;
//		while (start >= 0 && end < s.size()) {
//			if (s[start] != s[end]) break;
//			len = end - start + 1;
//			start--;
//			end++;
//		}
//		return len;
//	}
//
//public:
//	string longestPalindrome(string s) {
//		int len = 0, start = 0, end = 0;
//		for (int i = 0; i < s.size(); i++) {
//			int l1 = findLongest(s, i, i);
//			int l2 = findLongest(s, i, i + 1);
//			if (len >= l1 && len >= l2) continue;
//			if (l1 > l2) {
//				len = l1;
//				start = i - len / 2;
//				end = i + len / 2;
//			}
//			else {
//				len = l2;
//				//��ʵ������findLongestֱ�ӷ���{start,end}��������
//				//�Ƶ���ʽ��
//				//(i - start + 1) * 2 = len;
//				start = i - len / 2 + 1;
//				//(end - (i + 1) + 1) * 2 = len;
//				end = len / 2 + i;
//			}
//		}
//		//����1����ʼλ�ã�����2���Ӵ����ַ�����
//		return s.substr(start, end - start + 1);
//	}
//};

//class Solution {
//private:
//    pair<int, int> find(string& s, int start, int end) {
//        while (start >= 0 && end < s.size() && s[start] == s[end]) {
//            start--;
//            end++;
//        }
//        return { start + 1,end - 1 };
//    }
//public:
//    string longestPalindrome(string s) {
//        int start = 0, end = 0;
//        for (int i = 0; i < s.size(); i++) {
//            auto p1 = find(s, i, i);
//            auto p2 = find(s, i, i + 1);
//            if (p1.second - p1.first > end - start) {
//                start = p1.first;
//                end = p1.second;
//            }
//            if (p2.second - p2.first > end - start) {
//                start = p2.first;
//                end = p2.second;
//            }
//        }
//        return s.substr(start, end - start + 1);
//    }
//};

//class Solution {
//private:
//    pair<int, int> find(string& s, int start, int end) {
//        while (start >= 0 && end < s.size() && s[start] == s[end]) {
//            start--;
//            end++;
//        }
//        return { start + 1,end - 1 };
//    }
//public:
//    string longestPalindrome(string s) {
//        int start = 0, end = 0;
//        for (int i = 0; i < s.size(); i++) {
//            auto p1 = find(s, i, i);
//            auto p2 = find(s, i, i + 1);
//            if (p1.second - p1.first > end - start) {
//                start = p1.first;
//                end = p1.second;
//            }
//            if (p2.second - p2.first > end - start) {
//                start = p2.first;
//                end = p2.second;
//            }
//        }
//        return s.substr(start, end - start + 1);
//    }
//};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int start = 0, end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = (dp[i + 1][j - 1]) && (s[i] == s[j]);
                if (dp[i][j] && (j - i > end - start)) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
	Solution su;
	string ans = su.longestPalindrome("cbbd");
	cout << ans << endl;
}