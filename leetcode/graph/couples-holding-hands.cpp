#include <vector>
#include <iostream>

using namespace std;
/**
* 情侣牵手：https://leetcode.cn/problems/couples-holding-hands/
*
* 对于 row[i]，其男/女朋友为 row[i] ^ 1 (异或运算，其实只是改变了row[i]二进制右端的取值)
* (注意：好处是无论当前的值是奇数偶数，即数值二进制右端是0或1。而普通的+、-，需要先判断当前是奇数偶数，再来决定+、-1)
*
* 并查集：https://leetcode.cn/problems/couples-holding-hands/solution/qing-lu-qian-shou-by-leetcode-gl1c/
* 核心思路；如果我们有 k 对情侣形成了错误环，需要交换 k - 1 次才能让情侣牵手。
* 于是问题转化成 n / 2 对情侣中，有多少个这样的环。
*
* 贪心：（证明可参考：https://leetcode.cn/problems/couples-holding-hands/solution/liang-chong-100-de-jie-fa-bing-cha-ji-ta-26a6/)
*	贪心证明的思路：分析各种局部情况，然后从局部推到全局
*
* 广度优先搜索：https://leetcode.cn/problems/couples-holding-hands/solution/qing-lu-qian-shou-by-leetcode-solution-bvzr/
* 核心思路：将不匹配的row[i]、row[i + 1]，视为无向图上的连通的两个节点。然后用BFS遍历图。（可能是多个连通图组成的图，所以要遍历每个可能的起点，进行BFS）
*/
class UnionFind {
private:
	vector<int> parent;
	vector<int> weight;
	int count;

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
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;
		if (weight[x] > weight[y]) {
			//TODO 不要每次都写成x、y...
			parent[rootY] = rootX;
			weight[rootX] += weight[rootY];
		}
		else {
			parent[rootX] = rootY;
			weight[rootY] += weight[rootX];
		}
		count--;
	}
};

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		UnionFind uf(n);
		for (int i = 0; i < row.size(); i += 2) {
			uf.merge(row[i] / 2, row[i + 1] / 2);
		}
		return n - uf.getCount();
	}
};

int main() {
	Solution su;
	vector<int> row{ 5,4,2,6,3,1,0,7 };
	int ret = su.minSwapsCouples(row);
	cout << ret << endl;

}