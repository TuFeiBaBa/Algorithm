#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
* 反转字符串 https://leetcode.cn/problems/reverse-string/description/
*/
class Solution {
public:
	void reverseString(vector<char>& s) {
		//不需要i == j，同一个字符交换没有意义
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			//交换
			swap(s[i], s[j]);
		}
	}
};

int main() {
	string a = "abc";
	string b = "def";
	//string交换
	swap(a, b);
	cout << a << ',' << b << endl;
}