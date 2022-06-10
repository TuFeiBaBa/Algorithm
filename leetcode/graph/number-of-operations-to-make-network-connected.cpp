#include <vector>
using namespace std;
/*
* 连通网络的操作次数：https://leetcode.cn/problems/number-of-operations-to-make-network-connected/
*
* 思路：
*	1.什么时候，无法使所有网络都连通？2个点要连通，至少需要1条边。3个点至少需要2条边。以此类推，n个点，至少需要n - 1条边。
*	2.怎么计算需要几根网线才能使所有网络都连通。同思路1，每个连通的网络集，可以视为一个连通分量，或者视为一个点。
*	  将两个连通分量，连在一起，只需要一根网线。三个需要两根...
*
*/
class Solution {
private:
	vector<int> parent;
	vector<int> weight;
	int count;

	int find(int x) {
		if (x != parent[x]) {
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
		count--;
	}

public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (n > connections.size() + 1) return -1;
		parent = vector<int>(n);
		weight = vector<int>(n, 1);
		count = n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < connections.size(); i++) {
			merge(connections[i][0], connections[i][1]);
		}
		return count - 1;
	}
};

int main() {

}