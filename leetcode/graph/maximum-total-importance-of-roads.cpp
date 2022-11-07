#include <vector>
#include <algorithm>

using namespace std;
/*
* ��·���������Ҫ�� https://leetcode.cn/problems/maximum-total-importance-of-roads/description/
* 
* ��Ȼ�����Խ��ĵ㣬��Ҫ�Ը���
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
		//�����i��long���ͣ���ֹin[i] * (i + 1)�������
		//�����ǽ�in��Ϊvector<long>���ͣ���Ȼ�������˷ѿռ䡣
		for (long i = 0; i < n; i++) {
			ans += in[i] * (i + 1);
		}
		return ans;
	}
};

int main() {

}