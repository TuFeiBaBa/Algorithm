#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
/*
* ��Ч���ţ�https://leetcode.cn/problems/valid-parentheses/
* 
* �����������ڿ���ô�Ѵ���д�ø�����
* 
* ��׼˼·�ǣ�ջ����map�洢��Ӧ��ϵ��Ȼ��key��ջ������valueʱ�͵�ջ��
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
				//Ҫ�ж�ջ�Ƿ�Ϊ�գ�����: ']'
				if (st.empty() || m[c] != st.top()) {
					return false;
				}
				st.pop();
			}
		}
		//�������Ƶ����: '[('
		return st.empty();
	}
};

int main() {

}