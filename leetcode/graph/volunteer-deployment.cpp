#include <vector>

using namespace std;
class Solution {
public:
	vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
		int n = finalCnt.size() + 1;
		vector<vector<int>> g(n);
		for (int i = 0; i < edges.size(); i++) {
			g[edges[i][0]].emplace_back(edges[i][1]);
			g[edges[i][1]].emplace_back(edges[i][0]);
		}
		vector<long long> sum(n);
		for (int i = 0; i < finalCnt.size(); i++) {
			sum[i + 1] = finalCnt[i];
		}
		vector<long long> unknownNum(n);
		unknownNum[0] = 1;
		for (int i = plans.size() - 1; i >= 0; i--) {
			int plan = plans[i][0];
			int idx = plans[i][1];
			if (plan == 1) {

				sum[idx] *= 2;
			}
			else if (plan == 2) {
				for (int to : g[idx]) {
					sum[to] -= sum[idx];
					unknownNum[to] -= unknownNum[idx];
				}
			}
			else if (plan == 3) {
				for (int to : g[idx]) {
					sum[to] += sum[idx];
					unknownNum[to] += unknownNum[idx];
				}
			}
		}
		long long s = 0;
		long long u = 0;
		for (int i = 0; i < n; i++) {
			s += sum[i];
			u += unknownNum[i];
		}
		long long x = (totalNum - s) / u;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = sum[i] + unknownNum[i] * x;
		}
		return ans;
	}
};

int main() {
	vector<int> finalCnt = { 1,16 };
	vector<vector<int>> edges = { {0,1},{1,2} };
	vector<vector<int>> plans = { {2,1},{1,0},{3,0} };
	Solution su;
	su.volunteerDeployment(finalCnt, 21, edges, plans);
}