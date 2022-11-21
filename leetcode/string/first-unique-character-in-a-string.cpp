#include <queue>
#include <string>
#include <vector>

using namespace std;
/*
* 字符串中的第一个唯一字符 https://leetcode.cn/problems/first-unique-character-in-a-string/description/
*/
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> num(26);
		queue<pair<char, int>> pos;
		for (int i = 0; i < s.size(); i++) {
			if (!num[s[i] - 'a']) {
				pos.push({ s[i],i });
			}
			num[s[i] - 'a']++;
		}
		//queue无法这样操作
		// for(auto& p:pos){
		//不用队列也是可以的，只要从头到尾再遍历一次s，第一个num[s[i] - 'a'] == 1的，就是目标
		while (!pos.empty()) {
			auto& p = pos.front();
			if (num[p.first - 'a'] > 1) pos.pop();
			else return p.second;
		}
		return -1;
	}
};

int main() {

}