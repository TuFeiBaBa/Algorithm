#include <string>
#include <cassert>

using std::string;

/**
* 七进制数
* 
* https://leetcode-cn.com/problems/base-7/
* 分析：
* 1.num == 0
* 2.num < 0
* 3.num > 0
* 
* 10进制转换成其他进制：
* 当abs(num)大于0时，重复步骤1、2，直到num == 0
* 1.取余数：num % 7
* 2.取除法结果：num /= 7
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