#include <vector>
#include <string>

using namespace std;
/*
* 重复的子字符串 https://leetcode.cn/problems/repeated-substring-pattern/description/
*/
class Solution {
private:
	vector<int> next;
	void buildNext(string& s) {
		int k = 0;
		int i = 1;
		while (i < s.size()) {
			if (s[k] == s[i]) {
				next[i] = k + 1;
				i++;
				k++;
			}
			else if (k > 0) {
				k = next[k - 1];
			}
			else {
				i++;
			}
		}
	}

	bool kmp(string s, string p) {
		//使用reserve时，没有被初始化为0
		next.reserve(p.size());
		for (int i = 0; i < p.size(); i++) next[i] = 0;
		buildNext(p);
		// int s_pos = 0,pos = 0;
		// while(s_pos < s.size()){
		//     if(s[s_pos] == p[pos]){
		//         s_pos++;
		//         pos++;
		//     // }else if(next[pos - 1] > 0){
		//     }else if(pos > 0) {
		//         pos = next[pos - 1];
		//     }else{
		//         s_pos++;
		//     }

		//     if(pos == p.size()){
		//         // if(s_pos == p.size()){
		//         //     return true;
		//         // }else{
		//         //     return false;
		//         // }
		//         if(s_pos > p.size() && s_pos < s.size()) return true;
		//         pos = next[pos - 1];
		//     }
		// }

		//上面注释的是标准的kmp算法实现
		//下面的代码做了一点点改动，s_pos限定在0 < s_pos < s.size() - 1
		//因为比如"aaaa"和"aa"、"abcabc"和"abc"，无论是否满足题意的重复子字符串，[0,p.size() - 1]、[p.size(),s.size() - 1]
		//必然是等于p模式串的，所以要去头去尾
		int s_pos = 1, pos = 0;
		while (s_pos < s.size() - 1) {
			if (s[s_pos] == p[pos]) {
				s_pos++;
				pos++;
			}
			else if (pos > 0) {
				pos = next[pos - 1];
			}
			else {
				s_pos++;
			}

			if (pos == p.size()) {
				return true;
			}
		}
		return false;
	}
public:
	bool repeatedSubstringPattern(string s) {
		return kmp(s + s, s);
	}
};

int main() {

}