#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
/*
* 有效括号：https://leetcode.cn/problems/valid-parentheses/
* 
* 这道题更像是在考怎么把代码写得更优雅
* 
* 标准思路是：栈。用map存储对应关系。然后将key入栈。碰到value时就弹栈。
*/
class Solution {
private:
	unordered_map<char, char> m = {
		{')','('},
		{'}','{'},
		{']','['},
	};
public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s) {
			if (m.find(c) == m.end()) {
				st.push(c);
			}
			else {
				//要判断栈是否为空，处理: ']'
				if (st.empty() || m[c] != st.top()) {
					return false;
				}
				st.pop();
			}
		}
		//处理类似的情况: '[('
		return st.empty();
	}
};

int main() {

}