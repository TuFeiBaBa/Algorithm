#include <string>
#include <vector>

using namespace std;
/*
* 解码方法 https://leetcode.cn/problems//description/
* 
* dfs递归：时间复杂度最坏情况下是2 * 2 * 2 *...* 2，高达2^100，行不通
* 
* 动态规划：
*	要从前往后，从后往前"120"这种情况不好判断
*/
class Solution {
public:
	int numDecodings(string s) {
		//可以提前退出，但没有这个判断，后面的代码也能处理这种情况
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