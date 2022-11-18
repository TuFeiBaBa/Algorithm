#include <string>

using namespace std;
/*
* 验证回文串 https://leetcode.cn/problems/valid-palindrome/description/
*/
class Solution {
public:
	bool isPalindrome(string s) {
		string sgood;
		for (char ch : s) {
			if (isalnum(ch)) {
				sgood += tolower(ch);
			}
		}
		string sgood_rev(sgood.rbegin(), sgood.rend());
		return sgood == sgood_rev;
	}
};

int main() {
	
}