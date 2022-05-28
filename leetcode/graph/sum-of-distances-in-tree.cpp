#include <vector>
using namespace std;
/**
* 树中距离之和：https://leetcode.cn/problems/sum-of-distances-in-tree/
*
* 不完善的思路：
*	1.1 <= n <= 3 * 10^4。暴力解，获取一个节点的距离和，就要以该节点为根节点，遍历整颗树。遍历整颗树的时间是n。
*	  但是获取所有节点的距离，时间复杂度，就上升至O(n^2)了。
*	2.想办法优化时间复杂度：有没有办法先计算以某个节点为根节点，计算距离和。然后以此，快速推算其他点的距离和。
*	3.想一想，在遍历一颗树的时候，我们能获得什么？树的高度、前中后序、树的深度、【左子树、右子树大小，或者说节点数目】
*	4.（错误：没有注意到，如示例一，这不是个二叉树，而是N叉树）知道左右子树节点数目，当将根节点，移动到左节点时，
*	  左节点的距离和，必然要减少（左节点的子树节点数目 - 1）(距离拉近了)，加上（右节点的子树节点数目 + 1）(包括原根节点)
*
*	  正确思路：定义dp[u]表示以u为根的子树，它的所有子节点到它的距离之和，同时定义sz[u]表示以u为根的子树的节点数量（包括了u）。
*	  则			dp[u] = dp[v1] + sz[v1] + dp[v2] + sz[v2] + ...  (v1、v2是u的直接子节点)
*					sz[u] = sz[v1] + sz[v2]
*     我们遍历整棵树，自底向上，即可得到dp[root]
*	5.怎么构建树（这一点没有想明白）
*		1.edges并没有保证节点0就是根节点，也强调了树是无向的。所以无法以传统的方式，简单建立左节点、右节点这样的树类结构。
*		  以edges建图，只能建立无向图。
*	6.怎么遍历树（无向图）：有去无回法——检查是否是parent，是则跳过。如果只有一条边，那只能是parent了，可以确定到了树的根部。
*	7.状态转移：转移根节点，u->v
*		v不为u提供任何贡献了，所以			dp[u] = dp[u] - (dp[v] + sz[v])
*											sz[u] = sz[u] - sz[v]
*       u为新的根节点v提供了贡献，所以		dp[v] = dp[v] + (dp[u] + sz[u])
*											sz[v] = sz[v] + sz[u]
*/
class Solution {
private:
	vector<int> dp;
	vector<int> sz;
	vector<int> ans;
	void dfs(vector<vector<int>>& graph, int parent) {
		sz[parent] = 1;
		for (int e : graph[parent]) {
			if (sz[e] != 0) continue;
			dfs(graph, e);
			sz[parent] += sz[e];
			dp[parent] += dp[e] + sz[e];
		}
	}

	void dfs2(vector<vector<int>>& graph, int old, int n) {
		dp[old] = dp[old] - (dp[n] + sz[n]);
		sz[old] = sz[old] - sz[n];
		dp[n] = dp[n] + (dp[old] + sz[old]);
		sz[n] = sz[n] + sz[old];
		ans[n] = dp[n];
		for (int e : graph[n]) {
			if (e == old) continue;
			dfs2(graph, n, e);
		}
		//回溯
		//但写法有问题：应该考虑把前面的旧值缓存起来，减少计算
		dp[n] = dp[n] - (dp[old] + sz[old]);
		sz[n] = sz[n] - sz[old];
		dp[old] = dp[old] + (dp[n] + sz[n]);
		sz[old] = sz[old] + sz[n];
	}
public:
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n);
		dp = vector<int>(n);
		sz = vector<int>(n);
		ans = vector<int>(n);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		dfs(graph, 0);
		ans[0] = dp[0];
		//这里写得不好，统一整合到dfs2里更合适
		//参考：https://leetcode.cn/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
		for (int e : graph[0]) {
			dfs2(graph, 0, e);
		}
		return ans;
	}
};

int main() {

}