#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
* ���ظ��ַ�����Ӵ�:https://leetcode.cn/problems/longest-substring-without-repeating-characters/
*
* ����˼·����������
*
* ���ѵ㣺
*	1.��������߽磬��start
*	2."s ��Ӣ����ĸ�����֡����źͿո����"����ASCII�롣ASCII��ֵ��С���ǿ��ַ���
*
* �Ż���
*	�����߽磬��ʵ����Ϊ�˶�λǰ��͵�ǰ�ַ�һ�����ַ�λ�á�������������ͨ���ƶ�startָ��������
*	����ʱ�临�ӶȲ��ᳬ��O(n)������ͨ��map������ÿ���ַ����ֵ�λ�ã�������ٶ�λ��
* 
* �������������⣺C++�ı�����ʼ��
*/
//Ĭ�ϳ�ʼ��Ϊ0
static int nums[26];
class Solution {
	//Ĭ�ϳ�ʼ��Ϊ�����
	int num[26];
	//�ڳ�Ա�����в�����ôд���ھֲ������п��ԡ�
	//vector<int> vecNum(26);
	vector<int> vecNum = vector<int>(26);


public:
	//ֻ��������������г�ʼ������Ҫ�����ʼ����
	static int abc;
	//ֻ��������������г�ʼ������Ҫ�����ʼ����
	static int nums2[26];
	int lengthOfLongestSubstring(string s) {
		//��������
		//1.s�ﲻ���������ַ���
		//2.int[]��Ϊȫ�ֱ���ʱ���ŻὫֵĬ�ϳ�ʼ��Ϊ0����Ϊ�ֲ���������Ա����ʱ���ὫֵĬ�ϳ�ʼ��Ϊ0��
		//��ʼֵΪ���������vector<int>����Ĭ�ϳ�ʼ��Ϊ0��
		/*int record[26];*/
		vector<int> record(128);

		//----------����C++������ʼ��-----------
		//���־��ɣ����ǽ�����Ԫ�س�ʼ��Ϊ0
		//int record2[26]{ 0 };
		int record2[26] = { 0 };
		//����һ��Ԫ�س�ʼ��Ϊ1����������0
		int record3[26] = { 1};
		//����һ��Ԫ�س�ʼ��Ϊ1���ڶ���Ԫ�س�ʼ��Ϊ2����������0
		int record4[26] = { 1,2 };
		int r[26];
		nums[0] = 2;
		//�����������ʼ���������ͻᱨ��
		nums2[0] = 2;
		//�����������ʼ���������ͻᱨ��
		Solution::abc = 2;
		//----------����C++������ʼ��-----------


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
						//jҪ��ǰ��һλ
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