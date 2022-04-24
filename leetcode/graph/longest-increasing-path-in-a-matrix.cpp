#include <vector>
#include <iostream>

using namespace std;

/**
 * 矩阵中的最长递增路径: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * 解题思路：
 * 1.看题可知，任意一个matrix[i][j]点，都有四个方向可以移动。matrix本身已经是一个有向图，不需要再构建图
 * 2.每个点肯定都要尝试作为起点，走一遍
 *	1.这时候采用dp，可以记录已走过的节点。可以剪枝。
 *  2.动态方程是 dp[x][y] = max(dp[x][y],dp[nx][ny] + 1)
 * 3.每个点，能往另一个点走的前提是
 *	1.matrix[x][y] <= matrix[nx][ny]
 */
class Solution {
private:
	int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& move) {
		//if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) return 0;
		//剪枝
		if (dp[x][y] != -1) return dp[x][y];
		//默认是1
		int maxPath = 1;
		for (int i = 0; i < move.size(); i++) {
			int nx = x + move[i][0];
			int ny = y + move[i][1];
			if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
			if (matrix[x][y] <= matrix[nx][ny]) continue;
			maxPath = max(maxPath, dfs(nx, ny, matrix, dp, move) + 1);
		}
		dp[x][y] = maxPath;
		return maxPath;
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
		vector<vector<int>> move{ {0,1},{1,0},{0,-1},{-1,0} };
		int maxPath = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				int dist = dfs(i, j, matrix, dp, move);
				maxPath = max(maxPath, dist);
				//dp[i][j] = dist;
			}
		}
		return maxPath;
	}
};

int main() {
	vector <vector<int>> matrix{ {9,9,4 }, { 6,6,8 }, { 2,1,1 } };
	Solution su;
	int ret = su.longestIncreasingPath(matrix);
	cout << ret << endl;

	vector<vector<int>> matrix2{ {3,4,5 }, { 3,2,6 }, { 2,2,1 } };
	int ret2 = su.longestIncreasingPath(matrix2);
	cout << ret2 << endl;
}