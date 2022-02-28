#include <string>
#include <cassert>
using std::string;
/**
* 推多米诺
* https://leetcode-cn.com/problems/push-dominoes/
*
* 情况分析：
* 1）a b c : b为L/R，不受a、c影响
* 2）a b c : b为.
*   1.a为L，c为R，b不变
*   2.a为L，c为L，b为L
*   3.a为R，c为L，b不变
*   4.a为R，c为R，b为R
*   5.c为'.'，无法判断b的方向。先往前遍历，直到碰到第一个非'.'的c`。
*        1）如果c`为L。这时候，要看左边第一个不为'.'的情况
*           （1）为R，中间存在的多个连续'.'
*               ①连续'.'总数为奇数：中间的'.'不变，左边为R，右边为L
*               ②连续'.'总数为偶数：以中间为界限，左边为R，右边为L
*           （2）为L，中间存在的多个连续'.'均为L
*        2）如果c`为R，b要看左边第一个不为'.'的情况
*           （1）为L，中间存在的多个连续'.'不变
*           （2）为R，中间存在的多个连续'.'均为R
*
* 由于情况分析2）里的第五点，是将连续的'.'视为一个整体来处理。逻辑处理可以覆盖掉情况分析里2）的1、2、3、4中情况。
* 所以，我们只需要处理下面两种情况：
* 1）a b c : b为L/R，不受a、c影响
* 2）c为'.'，无法判断b的方向....
*
* 为什么要加哨兵：
* 考虑下列的排列，如果不加哨兵，代码会非常繁琐：
* R......
* L......
* ......R
* ......L
* .......
*
* 哨兵怎么加？
* 左边加个L，右边加个R。这样不会影响原排列。
*/

string pushDominoes(string dominoes) {
	int n = dominoes.length();
	int i = 0;
	
	while (i < n)
	{
		char left = i - 1 < 0? 'L':dominoes[i - 1];
		char right = 'R';
		int l = i, r = i;
		int k = i;
		while (dominoes[k] == '.' && k + 1 < n)
		{
			if (dominoes[k + 1] == '.') {
				k++;
			}
			else {
				right = dominoes[k + 1];
				break;
			}
		}
		if (k == i) {
			if (dominoes[k] == '.') {
				if (left == 'R' && right == 'R') {
					dominoes[k] = 'R';
				}
				else if (left == 'L' && right == 'L') {
					dominoes[k] = 'L';
				}
			}
			i++;
		}
		else {
			//不可行。比如i为1，k为2，center变为1了。索引1没有被更改。
			//int center = (k + i) / 2;
			//while (i <= k) {
			//	if (right == 'L') {
			//		if (left == 'R') {
			//			if (i < center) {
			//				dominoes[i] = 'R';
			//			}
			//			else if (i > center) {
			//				dominoes[i] = 'L';
			//			}
			//		}
			//		else
			//		{
			//			dominoes[i] = 'L';
			//		}
			//	}
			//	else {
			//		if (left == 'L') {
			//			i = k;
			//			break;
			//		}
			//		else {
			//			dominoes[i] = 'R';
			//		}
			//	}
			//	i++;
			//}
			int next = k + 1;
			while (i < k) {
				if (right == 'L' && left == 'R') {
						dominoes[i++] = 'R';
						dominoes[k--] = 'L';
					
				}
				else if (right == 'L' && left == 'L') {
					while (i <= k) {
						dominoes[i++] = 'L';
					}
				}
				else if (right == 'R' && left == 'R') {
					while (i <= k) {
						dominoes[i++] = 'R';
					}
				}
				else
				{
					break;
				}
			}
			i = next;
		}
	}
	return dominoes;
}

int main() {
	string s = pushDominoes("R...L");
	assert(s == "RR.LL");
}