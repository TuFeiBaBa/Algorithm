#include <vector>
#include <unordered_map>
using namespace std;

/*
* 移除最多的同行或同列石头: https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column
* 题解：https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/solution/947-yi-chu-zui-duo-de-tong-xing-huo-tong-ezha/
*
* 核心思想：一定可以把一个连通图里的所有顶点根据这个规则删到只剩下一个顶点。
*			所以：最多可以移除的石头的个数 = 所有石头的个数 - 连通分量的个数。（求连通分量的个数，可以使用并查集）
*
* 使用并查集的几个难点：
*		1.用什么来保存parent：用数组不行：不知道有多少个不同的x/y
*		2.怎么合并：当两个点的x或y相同时，这两个点就是连通的。但是如果是对两个点进行合并，代码逻辑不好处理。parent也不好定义。
*					换个思路：每个点其实我们都可以看成是一个连通图，它的x、y坐标必然同属于一个集合。根据x、y坐标来合并，
*					即对每个点自身的x、y进行合并。
*		3.怎么区分x、y坐标：石头的位置是「有序数对（二维）」，并查集的底层是「一维数组」，我们在并查集里应该如何区分横纵坐标呢？
*		4.count怎么计数
*
*/
class Solution {
private:
	int count;
	unordered_map<int, int> parent;
	unordered_map<int, int> weight;
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y) {
		if (parent.count(x) == 0) {
			parent[x] = x;
			weight[x] = 1;
			count++;
		}
		if (parent.count(y) == 0) {
			parent[y] = y;
			weight[y] = 1;
			count++;
		}
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
	int removeStones(vector<vector<int>>& stones) {
		for (int i = 0; i < stones.size(); i++) {
			merge(stones[i][0], stones[i][1] + 10000);
		}
		return stones.size() - count;
	}
};

int main() {

}