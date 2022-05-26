#include <vector>
#include <queue>
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
 *
 * 时间复杂度计算：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/
 */
class Solution {
	//private:
	//	int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& move) {
	//		//if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) return 0;
	//		//剪枝
	//		if (dp[x][y] != -1) return dp[x][y];
	//		//默认是1
	//		int maxPath = 1;
	//		for (int i = 0; i < move.size(); i++) {
	//			int nx = x + move[i][0];
	//			int ny = y + move[i][1];
	//			if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
	//			if (matrix[x][y] <= matrix[nx][ny]) continue;
	//			maxPath = max(maxPath, dfs(nx, ny, matrix, dp, move) + 1);
	//		}
	//		dp[x][y] = maxPath;
	//		return maxPath;
	//	}
	//
	//public:
	//	int longestIncreasingPath(vector<vector<int>>& matrix) {
	//		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
	//		vector<vector<int>> move{ {0,1},{1,0},{0,-1},{-1,0} };
	//		int maxPath = 0;
	//		for (int i = 0; i < matrix.size(); i++) {
	//			for (int j = 0; j < matrix[0].size(); j++) {
	//				int dist = dfs(i, j, matrix, dp, move);
	//				maxPath = max(maxPath, dist);
	//				//dp[i][j] = dist;
	//			}
	//		}
	//		return maxPath;
	//	}

public:
	/**
	* 拓扑排序+dist数组+松弛，可以用在DAG上面获取最短/最长路径，但是这里由于节点之间的边长都是1。
	* 所以只需要deep来记录路径BFS的层数（即边的数）
	*/
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		//vector<vector<int>> in(matrix.size(), vector<int>(matrix[0].size()));
		vector<vector<int>> out(matrix.size(), vector<int>(matrix[0].size()));
		vector<vector<int>> move{ {0,1},{1,0},{0,-1},{-1,0} };
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				for (int k = 0; k < move.size(); k++) {
					int nx = i + move[k][0];
					int ny = j + move[k][1];
					if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && matrix[i][j] < matrix[nx][ny]) {
						out[i][j]++;
					}
				}
			}
		}

		queue<pair<int, int>> q;
		//优化：可以合并到前面的遍历代码中去
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (out[i][j] == 0) q.emplace(i, j);
			}
		}
		int deep = 0;
		//相比较于DFS+记忆优化，BFS+拓扑排序，不需要记录已经走过节点（这是拓扑排序的特点决定的？）
		while (!q.empty()) {
			deep++;
			int size = q.size();
			for (int m = 0; m < size; m++) {
				pair<int, int> pos = q.front();
				q.pop();
				int i = pos.first;
				int j = pos.second;
				for (int k = 0; k < move.size(); k++) {
					int nx = i + move[k][0];
					int ny = j + move[k][1];
					if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && matrix[i][j] > matrix[nx][ny]) {
						out[nx][ny]--;
						if (out[nx][ny] == 0) q.emplace(nx, ny);
					}
				}
			}
		}
		return deep;
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