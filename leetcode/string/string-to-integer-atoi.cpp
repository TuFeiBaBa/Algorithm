#include <string>

using namespace std;
/*
* 字符串转换整数 (atoi)：https://leetcode.cn/problems/string-to-integer-atoi/
* 题解：https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
*
* 核心思想：有限状态机（finite-state machine，FSM，或者finite-state automaton，缩写：FSA。数学模型：自动机）
*
* 题解中的自动机表格：
*	  1.起始列表示当前状态，后续4列表示不同字符对应的下一个状态
*	  2.起始列的可选状态有4种，后续4列的可选状态，视起始列的可选状态和字符，结合题意而定（所以不等价于重复排列U(4,2)）
*/
class Solution {
public:
	int myAtoi(string s) {

	}
};
int main() {

}