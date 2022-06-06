#include <vector>
#include <string>
using namespace std;
/*
* 由斜杠划分区域：https://leetcode.cn/problems/regions-cut-by-slashes/
* 题解一：https://leetcode.cn/problems/regions-cut-by-slashes/solution/you-xie-gang-hua-fen-qu-yu-by-leetcode-67xb/
*		思路：将每个单元格格，延对角线分成4分。
*			1.单元格内合并：
				- 空格
				- 斜杠
				- 反斜杠
			2.单元格间合并：向右、向下
		思考：只是将每个单元格分成两份呢？如img\graph\regions-cut-by-slashes\1.png所示(还有空格的情况未画出)。
		答：应该能求得结果，但是耗时比原思路多。因为合并前，需要检查右、下两个单元格的情况(空格？斜杠？反斜杠？)，再根据情况合并。
* 题解二（转成求岛屿个数。并查集代码在评论区。比解法一更耗时，但思路更简单）：https://leetcode.cn/problems/regions-cut-by-slashes/solution/c-dong-hua-zhuan-huan-cheng-dao-yu-ge-sh-guve/
* 
* 核心思想：题目其实是考核连通性。考连通性，在目前已掌握的算法里面，应该优先选择并查集。
*/
class Solution {
public:
	int regionsBySlashes(vector<string>& grid) {

	}
};

int main() {

}