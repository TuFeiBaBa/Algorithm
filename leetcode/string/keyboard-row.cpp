#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
* 键盘行 https://leetcode.cn/problems/keyboard-row/description/
* 
* 官解：https://leetcode.cn/problems/keyboard-row/solutions/1069754/jian-pan-xing-by-leetcode-solution-bj5e/
*		直接将字母对应的行号，转换字符串"12210111011122000010020202"，天秀
*/
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> t = {
			{'q',0},{'w',0},{'e',0},{'r',0},{'t',0},{'y',0},{'u',0},{'i',0},{'o',0},{'p',0},
			{'a',1},{'s',1},{'d',1},{'f',1},{'g',1},{'h',1},{'j',1},{'k',1},{'l',1},
			{'z',2},{'x',2},{'c',2},{'v',2},{'b',2},{'n',2},{'m',2}
		};
		vector<string> ans;
		for (string& w : words) {
			int len = 0;
			int k = t[tolower(w[0])];
			for (char& c : w) {
				if (t[tolower(c)] != k) break;
				len++;
			}
			if (len == w.size()) ans.push_back(w);
		}
		return ans;
	}
};

int main() {

}