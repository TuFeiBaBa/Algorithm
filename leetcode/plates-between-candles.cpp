#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
class Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.length();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
		for (int i = 0; i < n; i++) {
			dp[i][i][1] = s[i] == '*' ? 1 : 0;
		}
		for (int len = 2; len <= n; len++) {
			for (int j = len - 1; j < n; j++) {
				int i = j + 1 - len;
				char c = s[j];
				if (c == '*') {
					dp[i][j][0] = dp[i][j - 1][0];
					dp[i][j][1] = dp[i][j - 1][1] + 1;
				}
				else {
					dp[i][j][0] = dp[i][j - 1][1] == ((j - 1) - i + 1) ? 0 : dp[i][j - 1][0] + dp[i][j - 1][1];
					dp[i][j][1] = 0;
				}
			}
		}

		int m = queries.size();
		vector<int> res(m);
		for (int i = 0; i < m; i++) {
			res[i] = dp[queries[i][0]][queries[i][1]][0];
		}
		return res;
	}
};

int main() {
	Solution sol;
	//s = "**|**|***|", queries = [[2,5],[5,9]]
	vector<vector<int>> queries{ {2,5},{5,9} };
	vector<int> res = sol.platesBetweenCandles("**|**|***|", queries);
	//std::cout << std::to_string(vector) << std::endl;
	std::ostream_iterator<int> it(std::cout, " ");
	std::copy(res.begin(), res.end(), it);
}