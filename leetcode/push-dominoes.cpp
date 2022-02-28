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
*   这里将一段连续的'.'视为b。
*   1.a、c同向时，b倒下同一方向
*   2.a、c相向时，b不变
*   3.a、c为相对时，b向中间倒：
*		 ①连续'.'总数为奇数：中间的'.'不变，左边为R，右边为L
*        ②连续'.'总数为偶数：以中间为界限，左边为R，右边为L
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
* 左边默认加个L，右边默认加个R。这样不会影响原排列。
*/

string pushDominoes(string dominoes) {
	int n = dominoes.length();
	int i = 0;

	while (i < n)
	{
		char left = i - 1 < 0 ? 'L' : dominoes[i - 1];
		char right = 'R';
		int l = i, r = i;
		int k = i;
		while (dominoes[k] == '.' && k < n)
		{
			k++;
		}
		right = k < n ? dominoes[k] : 'R';
		if (k == i) {
			i++;
			continue;
		}
		if (left == 'L' && right == 'R') {
			//do nothing
		}
		else if (right == left) {
			while (i < k) {
				dominoes[i++] = right;
			}
		}
		else {
			int j = k - 1;
			while (i < j) {
				dominoes[i++] = 'R';
				dominoes[j--] = 'L';
			}
		}
		i = k;
	}
	return dominoes;
}

int main() {
	string s = pushDominoes("R...L");
	assert(s == "RR.LL");
}