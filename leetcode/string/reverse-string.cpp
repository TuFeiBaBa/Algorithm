#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
* ��ת�ַ��� https://leetcode.cn/problems/reverse-string/description/
*/
class Solution {
public:
	void reverseString(vector<char>& s) {
		//����Ҫi == j��ͬһ���ַ�����û������
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			//����
			swap(s[i], s[j]);
		}
	}
};

int main() {
	string a = "abc";
	string b = "def";
	//string����
	swap(a, b);
	cout << a << ',' << b << endl;
}