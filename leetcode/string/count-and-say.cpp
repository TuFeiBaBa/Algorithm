#include <string>

using namespace std;
/*
* ������� https://leetcode.cn/problems/count-and-say/description/
*/
class Solution {
private:
	string dfs(int n) {
		if (n == 1) return "1";
		string s = dfs(n - 1);
		string ans;
		int cnt = 0;
		char num = s[0];
		for (char c : s) {
			if (num != c) {
				ans += cnt + '0';
				ans += num;
				cnt = 1;
				num = c;
			}
			else {
				cnt++;
			}
		}
		//forѭ����û�д������һ����
		ans += cnt + '0';
		ans += num;
		return ans;
	}
public:
	string countAndSay(int n) {
		return dfs(n);
	}
};

int main() {

}