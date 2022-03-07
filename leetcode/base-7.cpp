#include <string>
#include <cassert>

using std::string;

/**
* �߽�����
* 
* https://leetcode-cn.com/problems/base-7/
* ������
* 1.num == 0
* 2.num < 0
* 3.num > 0
* 
* 10����ת�����������ƣ�
* ��abs(num)����0ʱ���ظ�����1��2��ֱ��num == 0
* 1.ȡ������num % 7
* 2.ȡ���������num /= 7
*/
class Solution {
public:
    string convertToBase7(int num) {
		if (num == 0) return "0";
		string s = "";
		bool neg = num < 0;
		num = abs(num);
		while (num > 0)
		{
			s = std::to_string(num % 7) + s;
			num /= 7;
		}
		if (neg) {
			s = '-' + s;
		}

		return s;
    }
};

int main() {
	Solution sol;

	assert("202" == sol.convertToBase7(100));
}