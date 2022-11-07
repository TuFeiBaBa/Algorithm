#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

using namespace std;
/*
* 炸弹x可以引爆x自己，满足自反性 炸弹x可以引爆y，但y不一定可以引爆x，不满足对称性 炸弹x可以引爆y，y可以引爆z，得到x可以引爆z，满足传递性
* 所以这个关系不是等价关系，不能用并查集
*/
//class Solution {
//private:
//	vector<int> parent;
//	vector<int> weight;
//	int num = 0;
//
//	int find(int x) {
//		if (parent[x] != x) {
//			parent[x] = find(parent[x]);
//		}
//		return parent[x];
//	}
//
//	void merge(int x, int y) {
//		int rootX = find(x);
//		int rootY = find(y);
//		if (rootX == rootY) return;
//		if (weight[rootX] > weight[rootY]) {
//			parent[rootY] = rootX;
//			weight[rootX] += weight[rootY];
//			num = max(num, weight[rootX]);
//		}
//		else {
//			parent[rootX] = rootY;
//			weight[rootY] += weight[rootX];
//			num = max(num, weight[rootY]);
//		}
//	}
//
//public:
//	int maximumDetonation(vector<vector<int>>& bombs) {
//		int n = bombs.size();
//		parent = vector<int>(n);
//		weight = vector<int>(n, 1);
//		iota(parent.begin(), parent.end(), 0);
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				long x0 = bombs[i][0];
//				long y0 = bombs[i][1];
//				long r0 = bombs[i][2];
//				long x1 = bombs[j][0];
//				long y1 = bombs[j][1];
//				long r1 = bombs[j][2];
//				if ((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) <=  (r0 + r1) * (r0 + r1)) {
//					merge(i, j);
//				}
//			}
//		}
//		return num;
//	}
//};

/*
* 引爆最多的炸弹 https://leetcode.cn/problems/detonate-the-maximum-bombs/description/
*/
class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		int n = bombs.size();
		auto isConnect = [&](auto i, auto j)->bool {
			long x = bombs[i][0] - bombs[j][0];
			long y = bombs[i][1] - bombs[j][1];
			long r = bombs[i][2];
			return r * r >= x * x + y * y;
		};
		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && isConnect(i, j)) g[i].emplace_back(j);
			}
		}
		queue<int> q;
		int num = 0;
		for (int i = 0; i < n; i++) {
			vector<bool> used(n);
			q.push(i);

			/*int ans = 0;
			  while (!q.empty()) {
				int size = q.size();
				for (int j = 0; j < size; j++) {
					int node = q.front();
					q.pop();
					used[node] = true;
					for (int next : g[node]) {
						if (used[next]) continue;
						q.emplace(next);
					}
				}
				ans += size;
			}*/

			//一种解法：但有重复入队的问题。该代码模板常用于dijkstra算法
			/*int ans = 0;
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				if (used[node]) continue;
				used[node] = true;
				for (int next : g[node]) {
					q.emplace(next);
				}
				ans++;
			}*/


			//标准的BFS层序遍历，能避免重复入队问题
			int ans = 1;
			used[i] = true;
			while (!q.empty()) {
				int size = q.size();
				for (int j = 0; j < size; j++) {
					int node = q.front();
					q.pop();
					for (int next : g[node]) {
						if (used[next]) continue;
						used[next] = true;
						q.emplace(next);
						ans++;
					}
				}
				//ans += size;
			}

			num = max(num, ans);
		}
		return num;
	}
};

int main() {

}