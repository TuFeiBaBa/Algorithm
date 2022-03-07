#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* 1.节点直接不是树结构，是有环的
	*
	*/
	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
		int n = patience.size();
		sort(begin(edges), end(edges), [](const vector<int>& a,const vector<int>& b) { return a[0] < b[0]; });
		vector<int> minPaths(n, numeric_limits<int>::max());
		for (int i = 0; i < edges.size(); i++) {
			minPaths[edges[i][1]] = min(minPaths[edges[i][0] + 1], minPaths[edges[i][1]]);
		}
		int res = numeric_limits<int>::max();
		for (int i = 1; i < minPaths.size(); i++) {
			int curPath = minPaths[i];
			if (minPaths[i] < patience[i]) {
				res = max(curPath, res);
			}
			else {
				res = max(curPath % patience[i] + curPath,res);
			}
		}
		return 0;
	}
};

int main() {
	cout << (0 - numeric_limits<int>::min())<<endl;
};