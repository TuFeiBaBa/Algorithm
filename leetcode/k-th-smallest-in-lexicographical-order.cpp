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
		//1.�����ݹ�ģ���϶���ҪO(n)ʱ�临�Ӷȣ���������̫��O(n)Ҳ���У�
		//  1.ģ�⣺��ô�����Ǹ�����
		//  1.�ݹ飺
		//          1.��һ�β��ܴ�0��ʼ
		//          2.�ݹ���ֹ�����ִ���n�����ǵ���n��
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
				//���磬100~199��100�����֣�����k��101����ʱ��Ӧ��
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