#include <vector>
#include <queue>

using namespace std;
/*
* 飞地的数量 https://leetcode.cn/problems/number-of-enclaves/description/
* 
* 并查集的解法：自己的思路不全，可参考
* https://leetcode.cn/problems/number-of-enclaves/solutions/1252794/fei-di-de-shu-liang-by-leetcode-solution-nzs3/
*/
class Solution {
private:
	vector<vector<int>> move = { {1,0},{-1,0},{0,1},{0,-1} };

public:
	int numEnclaves(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int island = 0;
		queue<vector<int>> q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) island++;
				if (grid[i][j] && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
					grid[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		int nums = q.size();
		while (!q.empty()) {
			vector<int> is = q.front();
			q.pop();
			// if (!grid[is[0]][is[1]]) continue;
			// grid[is[0]][is[1]] = 0;
			for (int i = 0; i < move.size(); i++) {
				int nx = is[0] + move[i][0];
				int ny = is[1] + move[i][1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n || !grid[nx][ny]) continue;
				nums++;
				grid[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
		return island - nums;
	}
};

int main() {

}