#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
* 无重复字符的最长子串:https://leetcode.cn/problems/longest-substring-without-repeating-characters/
*
* 核心思路：滑动窗口
*
* 困难点：
*	1.如何收缩边界，即start
*	2."s 由英文字母、数字、符号和空格组成"，即ASCII码。ASCII码值最小的是空字符。
*
* 优化：
*	收缩边界，其实就是为了定位前面和当前字符一样的字符位置。下面做法，是通过移动start指针来处理，
*	整体时间复杂度不会超过O(n)。可以通过map来保存每个字符出现的位置，方便快速定位。
* 
* 碰到的其他问题：C++的变量初始化
*/
//默认初始化为0
static int nums[26];
class Solution {
	//默认初始化为随机数
	int num[26];
	//在成员变量中不能这么写。在局部变量中可以。
	//vector<int> vecNum(26);
	vector<int> vecNum = vector<int>(26);


public:
	//只是声明，不会进行初始化。需要类外初始化。
	static int abc;
	//只是声明，不会进行初始化。需要类外初始化。
	static int nums2[26];
	int lengthOfLongestSubstring(string s) {
		//两个错误：
		//1.s里不仅仅包含字符串
		//2.int[]作为全局变量时，才会将值默认初始化为0；作为局部变量、成员变量时不会将值默认初始化为0，
		//初始值为随机数。而vector<int>均会默认初始化为0。
		/*int record[26];*/
		vector<int> record(128);

		//----------测试C++变量初始化-----------
		//两种均可，都是将所有元素初始化为0
		//int record2[26]{ 0 };
		int record2[26] = { 0 };
		//将第一个元素初始化为1，其他均是0
		int record3[26] = { 1};
		//将第一个元素初始化为1，第二个元素初始化为2，其他均是0
		int record4[26] = { 1,2 };
		int r[26];
		nums[0] = 2;
		//不进行类外初始化，则编译就会报错
		nums2[0] = 2;
		//不进行类外初始化，则编译就会报错
		Solution::abc = 2;
		//----------测试C++变量初始化-----------


		int maxWin = 0, win = 0, start = 0;
		for (int i = 0; i < s.length(); i++) {
			int w = s[i] - ' ';
			if (record[w] == 0) {
				record[w]++;
				win++;
				maxWin = max(maxWin, win);
			}
			else {
				int j = start;
				while (j < i) {
					if (s[j] == s[i]) {
						//j要向前移一位
						j++;
						break;
					}
					record[s[j] - ' ']--;
					j++;
				}
				start = j;
				win = i - start + 1;
			}
		}
		return maxWin;
	}
};
int Solution::abc = 0;
int Solution::nums2[26];
int main() {
	Solution su;
	//int len = su.lengthOfLongestSubstring("abcabcbb");
	int len = su.lengthOfLongestSubstring(" ");
	Solution::abc = 0;
	cout << len << endl;
}