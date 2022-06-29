#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
* 电话号码的字母组合：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
*/
class Solution {

	//private:
	//	//如果用char来表示字符，还要转为string
	//	unordered_map<char, vector<string>> table{
	//			{'2',{"a","b","c"}},
	//			{'3',{"d","e","f"}},
	//			{'4',{"g","h","i"}},
	//			{'5',{"j","k","l"}},
	//			{'6',{"m","n","o"}},
	//			{'7',{"p","q","r","s"}},
	//			{'8',{"t","u","v"}},
	//			{'9',{"w","x","y","z"}},
	//	};
	//
	//	vector<string> dfs(string& digits, int i, vector<string> ans) {
	//		if (i >= digits.size()) return ans;
	//		vector<string> answer;
	//		for (string s : table[digits[i]]) {
	//			for (string& str : ans) {
	//				answer.push_back(str + s);
	//			}
	//		}
	//		return dfs(digits, i + 1, answer);
	//	}
	//
	//public:
	//	vector<string> letterCombinations(string digits) {
	//		if (digits.size() == 0) return {};
	//		return dfs(digits, 1, table[digits[0]]);
	//	}

/*
* 上面的解法每次都要先创建新的字符数组，拷贝之前状态的字符串。可优化成下述解法
*/
private:
	string str;
	vector<string> ans;
	//前面增加两个空字符串，是为了编码方便
	vector<string> table = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

	void dfs(string& digits, int i) {
		if (i >= digits.size()) {
			ans.push_back(str);
			return;
		}
		string& chars = table[digits[i] - '0'];
		for (int j = 0; j < chars.size(); j++) {
			//添加至字符串末尾
			str.push_back(chars[j]);
			dfs(digits, i + 1);
			//移除字符串末尾的字符
			str.pop_back();
		}
	}

public:
	vector<string> letterCombinations(string digits) {
		dfs(digits, 0);
		return ans;
	}
};

int main() {
	Solution su;
	su.letterCombinations("245");
}