#include <string>

using namespace std;
/*
* 最长特殊序列 Ⅰ https://leetcode.cn/problems/longest-uncommon-subsequence-i/description/
*/
class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a.size() > b.size()) return a.size();
		if (a.size() < b.size()) return b.size();
		return a == b ? -1 : a.size();
	}
};

int main() {

}