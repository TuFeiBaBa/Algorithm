#include <vector>
#include <algorithm>

using namespace std;
/*
* 道路的最大总重要性 https://leetcode.cn/problems/maximum-total-importance-of-roads/description/
* 
* 显然，入度越多的点，重要性更大
*/
class Solution {
public:
	long long maximumImportance(int n, vector<vector<int>>& roads) {
		vector<int> in(n);
		for (int i = 0; i < roads.size(); i++) {
			in[roads[i][0]]++;
			in[roads[i][1]]++;
		}
		sort(in.begin(), in.end());
		long long ans = 0;
		//这里的i是long类型，防止in[i] * (i + 1)计算溢出
		//而不是将in改为vector<long>类型：显然这样更浪费空间。
		for (long i = 0; i < n; i++) {
			ans += in[i] * (i + 1);
		}
		return ans;
	}
};

int main() {

}