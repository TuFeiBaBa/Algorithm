#include <queue>
#include <string>
#include <vector>

using namespace std;
/*
* �ַ����еĵ�һ��Ψһ�ַ� https://leetcode.cn/problems/first-unique-character-in-a-string/description/
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
		//queue�޷���������
		// for(auto& p:pos){
		//���ö���Ҳ�ǿ��Եģ�ֻҪ��ͷ��β�ٱ���һ��s����һ��num[s[i] - 'a'] == 1�ģ�����Ŀ��
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