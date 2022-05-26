#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/**
 * �����е������·��: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * ����˼·��
 * 1.�����֪������һ��matrix[i][j]�㣬�����ĸ���������ƶ���matrix�����Ѿ���һ������ͼ������Ҫ�ٹ���ͼ
 * 2.ÿ����϶���Ҫ������Ϊ��㣬��һ��
 *	1.��ʱ�����dp�����Լ�¼���߹��Ľڵ㡣���Լ�֦��
 *  2.��̬������ dp[x][y] = max(dp[x][y],dp[nx][ny] + 1)
 * 3.ÿ���㣬������һ�����ߵ�ǰ����
 *	1.matrix[x][y] <= matrix[nx][ny]
 *
 * ʱ�临�Ӷȼ��㣺https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/
 */
class Solution {
	//private:
	//	int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& move) {
	//		//if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) return 0;
	//		//��֦
	//		if (dp[x][y] != -1) return dp[x][y];
	//		//Ĭ����1
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
	* ��������+dist����+�ɳڣ���������DAG�����ȡ���/�·���������������ڽڵ�֮��ı߳�����1��
	* ����ֻ��Ҫdeep����¼·��BFS�Ĳ��������ߵ�����
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
		//�Ż������Ժϲ���ǰ��ı���������ȥ
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (out[i][j] == 0) q.emplace(i, j);
			}
		}
		int deep = 0;
		//��Ƚ���DFS+�����Ż���BFS+�������򣬲���Ҫ��¼�Ѿ��߹��ڵ㣨��������������ص�����ģ���
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