#include <vector>
#include <iostream>
using namespace std;
/**
* 省份数量：https://leetcode.cn/problems/number-of-provinces/
* 并查集时间复杂度分析：https://blog.csdn.net/yuzhiqiang666/article/details/80721436
*/
class UnionFind {
public:
	UnionFind(int n) {
		count = n;
		parent = vector<int>(n);
		weight = vector<int>(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			weight[i] = 1;
		}
	}

	int getCount() {
		return count;
	}

	int find(int x) {
		//不是用while，用if
		if (x != parent[x]) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	bool isConnect(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;
		count--;

		//错误写法：应该更改根节点
		//if (weight[x] > weight[y]) {
		//	parent[y] = rootX;
		//}
		//else {
		//	parent[x] = rootY;
		//}
		if (weight[rootX] > weight[rootY]) {
			weight[rootX] += weight[rootY];
			parent[rootY] = rootX;
		}
		else {
			weight[rootY] += weight[rootX];
			parent[rootX] = rootY;
		}
	}

private:
	int count;
	vector<int> parent;
	vector<int> weight;
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		UnionFind uf(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//i == j时，是同一个城市，不需要判断
				if (isConnected[i][j] == 1 && i != j) {
					uf.merge(i, j);
				}
			}
		}

		//不需要再判断isConnected[i][j] == 0的情况
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isConnected[i][j] == 0 && uf.isConnect(i,j)) {
					uf.merge(i, j);
				}
			}
		}*/

		return uf.getCount();
	}
};

int main() {
	Solution su;
	vector<vector<int>> isConnected{ {1,1,1},{1,1,1},{1,1,1} };
	int num = su.findCircleNum(isConnected);
	cout << num << endl;
}