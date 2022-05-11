/**
* 冗余连接：https://leetcode.cn/problems/redundant-connection/
*
* 错误思路：构建图，然后在构建图的过程中，找到环。遍历环，用map来判断边在edges中出现的顺序，满足"最后出现的边"这个要求。（应该也能解，但是过于复杂，时间复杂度也不是最优）
*
* 正确思路：并查集
* 1.遍历edges，判断组成边的两个节点，是否是连通分量：
*    1.不是，合并他们
*    2.是，他们就是附加边
*
* 并查集的做法，是如何满足"最后出现的边"这个要求?
* 遍历edges数组本身就是构建图的过程，当遇到一条边的两个点连通时,说明有另外一条路径连接了这两个点。
* 如果再加上这条边就会变成环，然后这条边刚好是数组中组成这个环的最后一条边，满足"最后出现的边"这个条件。
*
*/
#include <vector>
using namespace std;
class Solution {
private:
	int find(vector<int>& parent, int x) {
		if (x != parent[x]) {
			parent[x] = find(parent, parent[x]);
		}
		return parent[x];
	}

	void merge(vector<int>& parent, int x, int y) {
		int rootX = find(parent, x);
		int rootY = find(parent, y);
		parent[rootX] = rootY;
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1);
		for (int i = 0; i < n + 1; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < edges.size(); i++) {
			if (find(parent, edges[i][0]) != find(parent, edges[i][1])) {
				merge(parent, edges[i][0], edges[i][1]);
			}
			else {
				return edges[i];
			}
		}
		return vector<int>{};
	}
};


int main() {

}