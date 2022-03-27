#include <vector>
using namespace std;
/**
* 贪心算法
**/
class Solution {
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int m = rolls.size();
		int len = rolls.size() + n;
		int sum = mean * len;
		int sumM = 0;
		for (int i = 0; i < m; i++) {
			sumM += rolls[i];
		}
		int sumN = sum - sumM;
		if (sumN > 6 * n || sumN < n) {
			return vector<int>();
		}
		else if (sumN % n == 0) {
			return vector<int>(n, sumN / n);
		}
		else {
			int extra = sumN % n;
			//人人都说贪心，这写法不太明白哪里体现贪心了
			//vec的初始化算一种另类的贪心？
			vector<int> vec(n, sumN / n);
			for (int i = 0; i < extra; i++) {
				vec[i] = vec[i] + 1;
			}
			return vec;
		}
	}
};

int main() {

}