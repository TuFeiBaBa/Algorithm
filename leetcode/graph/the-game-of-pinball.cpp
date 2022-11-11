#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
//class Solution {
//private:
//	vector<vector<int>> move = { {-1,0},{1,0},{0,-1},{0,1} };
//public:
//	vector<vector<int>> ballGame(int num, vector<string>& plate) {
//		int m = plate.size();
//		int n = plate[0].size();
//		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n.vector<int>(4, INT_MAX));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; i < n; j++) {
//				int t = plate[i][j];
//				if (t != 'O') continue;
//				queue<vector<int>> q;
//				for (int k = 0; k < move.size(); k++) {
//					int ni = i + move[k][0];
//					int nj = j + move[k][1];
//					if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
//					if (plate[ni][nj] == '.') {
//						q.push({ ni,nj });
//						dp[ni][nj][k] = min(dp[ni][nj][k], 1);
//					}
//					else if (plate[ni][nj] == 'O') {
//						continue;
//					}if (plate[ni][nj] == 'W') {
//						if (ni < i) {
//
//						}
//					}
//				}
//				while (!q.empty()) {
//					auto [x, y] = q.front();
//					q.pop();
//
//				}
//			}
//		}
//	}
//};

/*
* ������Ϸ https://leetcode.cn/problems/EXvqDp/description/
*
* һ��ʼ����ʱ�临�Ӷȵ�ʱ����Ϊ��O(mn(m + n))����ģ�ֻ���ü����Ż���
* ��ʵ�������ʱ�临�Ӷ���O(m * max(m,n) + n * max(m,n)),����ΪO(mn)����Ϊ��ÿ������ĵ��飬
* ·���ǹ̶��ģ�����ᳬ��max(m,n)��
*
* ����Ƚϳ�ª�����õ��˵ݹ飬�ռ临�Ӷ�ΪO(max(m,n))���ɲο� https://leetcode.cn/problems/EXvqDp/solutions/1847059/mei-ju-by-endlesscheng-5wzf/
* ����㣺
* 1)dfs�����ɸ�Ϊ����
* 2)move�����Ϊ{{0,1},{1,0},{0,-1},{-1,0}����ô��ǰ����Ϊkʱ����ʱ����� (k + 3) % 4��˳ʱ����(k + 1) % 4
*/
class Solution {
private:
	vector<vector<int>> move = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>> next = { {2,3,1,0},{3,2,0,1} };
	bool dfs(int num, vector<string>& plate, int i, int j, int k) {
		if (num < 0 || i < 0 || i >= plate.size() || j < 0 || j >= plate[0].size()) return false;
		int c = plate[i][j];
		if (c == 'O') return true;
		if (c == '.') return dfs(num - 1, plate, i + move[k][0], j + move[k][1], k);
		if (c == 'W') return dfs(num - 1, plate, i + move[next[0][k]][0], j + move[next[0][k]][1], next[0][k]);
		if (c == 'E') return dfs(num - 1, plate, i + move[next[1][k]][0], j + move[next[1][k]][1], next[1][k]);
		return false;
	}
public:
	vector<vector<int>> ballGame(int num, vector<string>& plate) {
		int m = plate.size();
		int n = plate[0].size();
		vector<vector<int>> ans;
		for (int i = 1; i < m - 1; i++) {
			//������ֻ�ܴӿհ��������룺plate[i][0] == '.'
			if (plate[i][0] == '.' && dfs(num, plate, i, 0, 3)) {
				ans.push_back({ i, 0 });
			}
			if (plate[i][n - 1] == '.' && dfs(num, plate, i, n - 1, 2)) {
				ans.push_back({ i, n - 1 });
			}
		}
		for (int j = 1; j < n - 1; j++) {
			if (plate[0][j] == '.' && dfs(num, plate, 0, j, 1)) {
				ans.push_back({ 0, j });
			}
			if (plate[m - 1][j] == '.' && dfs(num, plate, m - 1, j, 0)) {
				ans.push_back({ m - 1, j });
			}
		}
		return ans;
	}
};

int main() {

}