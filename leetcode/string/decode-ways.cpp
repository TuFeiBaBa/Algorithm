#include <string>
#include <vector>

using namespace std;
/*
* ���뷽�� https://leetcode.cn/problems//description/
* 
* dfs�ݹ飺ʱ�临�Ӷ���������2 * 2 * 2 *...* 2���ߴ�2^100���в�ͨ
* 
* ��̬�滮��
*	Ҫ��ǰ���󣬴Ӻ���ǰ"120"������������ж�
*/
class Solution {
public:
	int numDecodings(string s) {
		//������ǰ�˳�����û������жϣ�����Ĵ���Ҳ�ܴ����������
		if (s[0] == '0') return 0;
		vector<int> nums(s.size() + 1);
		nums[0] = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '0') nums[i + 1] += nums[i];
			if (i > 0 && (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26))
				nums[i + 1] += nums[i - 1];

		}
		return nums[s.size()];
	}
};

int main() {

}