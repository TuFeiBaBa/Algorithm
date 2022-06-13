#include <string>

using namespace std;
/*
* 整数转罗马数字：https://leetcode.cn/problems/integer-to-roman/
* 
* 题解：https://leetcode.cn/problems/integer-to-roman/solution/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/
* 
* 思路：十进制的每个位置的数字，可以用罗马数字单独翻译，互不影响
* 
* 两种方法：
*	1.模拟：先翻译高位数字。针对十进制的每个位置，使用贪心算法，优先选择考虑能否翻译成较大的罗马数字
*	2.硬编码数字：1 <= num <= 3999。数值是有限的，每个位置又可以单独翻译。所以，可以建立一个二维的表格，
*	  根据位置、具体数字，直接填写对应的罗马数字。翻译的时候，查询表格即可。
*/
class Solution {
public:
	string intToRoman(int num) {

	}
};

int main() {

}