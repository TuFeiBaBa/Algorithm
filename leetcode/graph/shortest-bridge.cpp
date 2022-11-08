#include <vector>
#include <numeric>

using namespace std;
/*
* ��̵��� https://leetcode.cn/problems/shortest-bridge/description/
* 
* ˼·�����鼯�ֱ��ҵ��������졣Ȼ���ٽ���������ĵ�鲢��������ͬ�ļ��ϡ�����������ϵĵ㣬�����Ƚϡ�
* ʱ�临�Ӷȣ���������������ռ½�ص�1/2����ÿ������Ĵ�С����Ϊ n^2 * (1/4)�������Ƚϵ�ʱ�临�Ӷ�ΪO(n^4)��
* 
* ���Ž⣺https://leetcode.cn/problems/shortest-bridge/solutions/1922327/-by-muse-77-j7w5/
*/
class Solution {
private:
	vector<int> parent;
	vector<int> weight;

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;
		if (weight[rootX] > weight[rootY]) {
			parent[rootY] = rootX;
			weight[rootX] += weight[rootY];
		}
		else {
			parent[rootX] = rootY;
			weight[rootY] += weight[rootX];
		}
	}

public:
	int shortestBridge(vector<vector<int>>& grid) {
		int n = grid.size();
		parent = vector<int>(n * n);
		weight = vector<int>(n * n, 1);
		iota(parent.begin(), parent.end(), 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!grid[i][j]) continue;
				if (i - 1 >= 0 && grid[i - 1][j] == 1) {
					merge(i * n + j, (i - 1) * n + j);
				}
				if (j - 1 >= 0 && grid[i][j - 1] == 1) {
					merge(i * n + j, i * n + j - 1);
				}
			}
		}

		//int island = -1;
		int iParent = -1;
		//vector<vector<int>> g(n, vector<int>(n));
		vector<vector<int>> set0;
		vector<vector<int>> set1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!grid[i][j]) continue;
				if (iParent == -1) iParent = find(i * n + j);

				if (find(i * n + j) == iParent) {
					//g[i][j] = 1;
					// vector<int>(i,j)������{i,j}
					//set0.push_back(vector<int>(i, j));
					set0.push_back({ i,j });
				}
				else {
					//g[i][j] = 2;
					//set1.push_back(vector<int>(i, j));
					set1.push_back({ i,j });
				}
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < set0.size(); i++) {
			for (int j = 0; j < set1.size(); j++) {
				int i0 = set0[i][0];
				int j0 = set0[i][1];
				int i1 = set1[i][0];
				int j1 = set1[i][1];
				ans = max(ans, abs(i0 - i1) + abs(j0 - j1));
			}
		}
		return ans;
	}
};

int main() {

}