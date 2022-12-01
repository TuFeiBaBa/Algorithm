#include <string>
#include <vector>
#include <iostream>

using namespace std;
//class Solution {
//private:
//	bool simplify(string& p) {
//		if (p.empty()) return false;
//		if (p.size() >= 3 && p[p.size() - 1] == '.' && p[p.size() - 2] == '.' && p[p.size() - 3] == '/') {
//			int splitNum = 0;
//			int j = p.size() - 1;
//			while (j >= 1) {
//				if (p[j] == '/') splitNum++;
//				if (splitNum == 2) break;
//				p.pop_back();
//				j--;
//			}
//			return true;
//		}
//		else if (p.size() >= 2 && p[p.size() - 1] == '.' && p[p.size() - 2] == '/') {
//			p.pop_back();
//			return true;
//		}
//		else if (p[p.size() - 1] == '/') {
//			return true;
//		}
//		return false;
//	}
//
//public:
//	string simplifyPath(string path) {
//		string ans;
//		for (auto& c : path) {
//			bool is = false;
//			if (c == '/') {
//				is = simplify(ans);
//			}
//			if (!is) ans += c;
//		}
//		simplify(ans);
//		if (!ans.empty() && ans[ans.size() - 1] == '/') ans.pop_back();
//		return ans.empty() ? "/" : ans;
//	}
//};

/*
* ¼ò»¯Â·¾¶ https://leetcode.cn/problems/simplify-path/description/
*/
class Solution {
public:
	string simplifyPath(string path) {
		auto split = [](string& s, char p)->vector<string> {
			vector<string> strs;
			string cur;
			for (auto& c : s) {
				if (c == p) {
					if (!cur.empty()) strs.push_back(move(cur));
					cur.clear();
				}
				else {
					cur += c;
				}
			}
			if (!cur.empty()) strs.push_back(move(cur));
			return strs;
		};
		vector<string> names = split(path, '/');
		vector<string> stack;
		for (string& s : names) {
			if (s == "..") {
				if (!stack.empty()) stack.pop_back();
			}
			else if (s != ".") {
				stack.push_back(move(s));
			}
		}
		string ans;
		if (stack.empty()) {
			ans = "/";
		}
		else {
			for (auto& s : stack) {
				ans += "/" + s;
			}
		}
		return ans;
	}
};

int main() {
	Solution su;
	string ans = su.simplifyPath("/a/../");
	string a;
	cout << ans << endl;
}