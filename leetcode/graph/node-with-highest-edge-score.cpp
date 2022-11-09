#include <vector>
#include <numeric>

using namespace std;
/*
* 边积分最高的节点 https://leetcode.cn/problems/node-with-highest-edge-score/description/
* 
* 该题陷阱在于计算溢出。
*/
class Solution {
public:
	int edgeScore(vector<int>& edges) {
		int n = edges.size();
		//vector<int> r(n,0);
		vector<long long> r(n, 0);
		for (int i = 0; i < n; i++) {
			r[edges[i]] += i;
		}
		//int score = 0;
		long long score = 0;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (r[i] > score) {
				score = r[i];
				idx = i;
			}
		}
		return idx;
	}
};

int main() {

}