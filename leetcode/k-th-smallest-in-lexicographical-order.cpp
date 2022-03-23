#include <iostream>
class Solution {
public:
	int k = 0;
	int findKth(int num, int n) {
		
		for (int i = 0; i <= 9; i++) {
			long m = (long)num * 10 + i;
			if (m > n) return -1;
			k--;
			if (k == 0) return m;
			int res = findKth(m, n);
			if (res > 0) return res;
		}
		return -1;
	}

	int findKthNumber(int n, int k) {
		//1.看数据规模，肯定需要O(n)时间复杂度？（数据量太大，O(n)也不行）
		//  1.模拟：怎么排序是个问题
		//  1.递归：
		//          1.第一次不能从0开始
		//          2.递归终止：数字大于n。不是等于n。
		if (n <= 9) return k;
		this->k = k;
		for (int i = 1; i <= 9; i++) {
			this->k--;
			if (k == 0) return i;
			int res = findKth(i, n);
			if (res > 0) return res;
		}

		int num = 1;
		k--;
		while (k > 0)
		{
			int step = findKth(num, n);
			if (step <= k) {
				k -= step;
				//比如，100~199有100个数字，但是k是101，这时候，应该
				num++;
			}
		}

		return 0;
	}
};

int main() {
	Solution su;
	int res = su.findKthNumber(957747794,424238336);
	std::cout << res << std::endl;
}