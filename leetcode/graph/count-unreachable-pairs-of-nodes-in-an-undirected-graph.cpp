#include <vector>
#include <unordered_map>

using namespace std;
/*
* 统计无向图中无法互相到达点对数 https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
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
	long long countPairs(int n, vector<vector<int>>& edges) {
		parent = vector<int>(n);
		weight = vector<int>(n, 1);
		iota(parent.begin(), parent.end(), 0);
		for (auto edge : edges) {
			merge(edge[0], edge[1]);
		}

		unordered_map<int,int> record;
		for (int i = 0; i < n; i++) {
			int root = find(i);
			if (!record.count(root)) {
				record[root] = weight[root];
			}
		}
		//n * (n - 1) / 2LL不行，n * (n - 1)还是可能发生截断
		//ans表示每个点都不联通时，不可互相抵达的不同点对数目
		long long ans = (long long) n * (n - 1) / 2;
		for (auto [_, cnt] : record) {
			//用组合数做减法：总数量减去能相互连通的数量
			ans -= (long long) cnt * (cnt - 1) / 2;
		}
		return ans;
	}
};

int main() {

}

