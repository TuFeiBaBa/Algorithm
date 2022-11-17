#include <string>

using namespace std;
/*
* 找出字符串中第一个匹配项的下标 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/
class Solution {
private:
	void buildNext(vector<int>& next, string needle) {
		int i = 1;
		int k = 0;
		while (i < needle.size()) {
			if (needle[i] == needle[k]) {
				next[i] = k + 1;
				k++;
				i++;
			}
			else if (k != 0) {
				k = next[k - 1];
			}
			else {
				i++;
			}
		}
	}

public:
	int strStr(string haystack, string needle) {
		vector<int> next(needle.size());
		buildNext(next, needle);
		int s_pos = 0;
		int pos = 0;
		while (s_pos < haystack.size()) {
			if (haystack[s_pos] == needle[pos]) {
				s_pos++;
				pos++;
			}
			else if (pos > 0) {
				pos = next[pos - 1];
			}
			else {
				s_pos++;
			}
			if (pos == needle.size()) {
				return s_pos - pos;
			}
		}
		return -1;
	}
};

int main() {

}