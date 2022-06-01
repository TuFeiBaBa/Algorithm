#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;
/**
* 访问所有节点的最短路径：https://leetcode.cn/problems/shortest-path-visiting-all-nodes/
*
* 思路：
*	1.算法挑选：有环、终点、起点不确定、最短路径与常规的不一样，边可重复经过：
*	  所以拓扑排序（有环）、关键路径（有环）、Dijkstra（非单源且边可重复经过）、Bellman-Ford（非单源且边可重复经过）等算法都不适用
*	2.从不同的节点开始，形成的最短路径，可能不同，无有效手段，快速确定哪条是最长，所以，只能暴力地尝试所有的情况。
*	3.尝试优化一下暴力解：
*		0		 1
*		 \		/
*		  \	   /
*			2
*	  如上，这是树的局部图（节点2后面还有一堆节点未画出来）。
*	  假设从节点0开始，路径为[0,2,1,2]。从节点1开始，路径为[1,2,0,2]。这两种起始情况，经过的节点，路径的长度是相同的，所以完全可以合并。
*
*	  问题：有没有经过节点一样，但路径长度不一样的情况？
*	  答：有。比如，从2开始的话，起始路径为[2，0，2，1，2]，都是经过了[0,1,2]三个节点，但路径长度显然大于上面两种起始情况。
*
*	  问题：如何处理上述情况？
*	  答：使用广度优先搜索。那么，经过节点[0，1，2]三个节点的最短的路径，必然最先进入队列中等待下一次出队。经过同样节点的，较长的路径，
*	  也就可以被排除在外面了。
*
*	  问题：如何使用记忆优化，即剪枝？以从节点0开始为例，路径[0,2,1]已经经历了节点[0,1,2]三个节点，如果是单纯地用mark进行标记，
*	  0、1、2都已经把标记位置为1了。这样的情况，如何表示重复经过[1，2]这条边，回到节点2，继续遍历？
*	  答：数组seen解决不了这样的情况，seen[mark]为true时，路径mark（比如路径为[0,2，1，2]时，mark的二进制表示为11100...）已经访问过了。
*	  显然，seen数组能提供的信息不足，区分不了这种情况。注意：[0,2,1]与[0,2,1,2]的相同在于，二进制标记位都是11100..，不同在于当前所在点不一样。
*	  所以，需要增加当前所在位置的信息。用矩阵seen来记录。seen[i][mark]为true时，表示当经过节点i时，路径mark已经访问过，不需要重复入队该情况（用于剪枝）。
*
* 时间复杂度：
*	  常规的广度优先搜索的时间复杂度为 O(n + m)，其中 n 和 m 分别表示图的节点数和边数。本题中引入了 mask 这一维度，其取值范围为 [0, 2^n)，
*	  因此可以看成是进行了 2^n 次常规的广度优先搜索。由于 m 的范围没有显式给出，在最坏情况下为完全图，利用组合可知，有n(n - 1)/2条边，
*	  所以有 m = O(n^2)，因此总时间复杂度为O(n^2 * 2^n)
*
* 空间复杂度：O(n * 2^n)，即为seen需要使用的空间
*/
//class Solution {
//public:
//	int shortestPathLength(vector<vector<int>>& graph) {
//		int n = graph.size();
//		//mark的二进制形式，一共有n位，可选值为0、1
//		//其实就是重复排列，U(m,n) = n^m = 2^n
//		//2^n,其实就是1 << n
//		vector<vector<bool>> seen(n, vector<bool>(1 << n));
//		queue<tuple<int, int, int>> q;
//		for (int i = 0; i < graph.size(); i++) {
//			q.emplace(i, 1 << i, 0);
//		}
//		int full = (1 << n) - 1;
//		while (!q.empty()) {
//			tuple<int, int, int>& t = q.front();
//			//会释放资源，导致addresssanitizer heap-use-after-free
//			//q.pop();
//			int i = get<0>(t);
//			int mark = get<1>(t);
//			int d = get<2>(t);
//			q.pop();
//			if (mark == full) return d;
//			for (int j : graph[i]) {
//				//这里应该是二进制操作..记得加括号..
//				//int markJ = mark + (1 << j);
//				int markJ = mark | (1 << j);
//				//在这里return，应该更好、更及时，即使是n为1的情况，进不来，但是后面return 0，也能覆盖
//				//if (markJ == full) return d + 1;
//				if (!seen[j][markJ]) {
//					seen[j][markJ] = true;
//					q.emplace(j, markJ, d + 1);
//				}
//			}
//		}
//		return 0;
//	}
//};

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> d(n, vector<int>(n, n + 1));
		for (int i = 0; i < n; ++i) {
			for (int j : graph[i]) {
				d[i][j] = 1;
			}
		}
		// 使用 floyd 算法预处理出所有点对之间的最短路径长度
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
		for (int mask = 1; mask < (1 << n); ++mask) {
			//如果 mask 只包含一个 1，即 mask 是 2 的幂
			if ((mask & (mask - 1)) == 0) {
				//C++ __builtin_系列函数:https://blog.csdn.net/yandaoqiusheng/article/details/102920785
				int u = __builtin_ctz(mask);
				//由于可以将任意点作为起点出发，可以将这些起点的最短距离（步长）设置为 0
				//也可以在遍历mask之前，通过下列代码进行初始化
				//for (int i = 0; i < n; i++) f[i][1 << i] = 0;

				//在这里初始化，不会导致问题？
				//不会。在整个动态规划过程中，假设u-v是一条边。v的序号大于u。f[u][mask]中的mask是不会使用到v的。
				//f[v][mask]才会使用到u。换个角度想想，u-v是无向的。计算出f[v][mask]就是计算u-v的最短路径。
				f[u][mask] = 0;
			}
			else {
				for (int u = 0; u < n; ++u) {
					if (mask & (1 << u)) {
						for (int v = 0; v < n; ++v) {
							if ((mask & (1 << v)) && u != v) {
								f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] + d[v][u]);
							}
						}
					}
				}
			}
		}

		int ans = INT_MAX;
		for (int u = 0; u < n; ++u) {
			ans = min(ans, f[u][(1 << n) - 1]);
		}
		return ans;
	}
};

int main() {
	//vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	Solution su;
	int shortest = su.shortestPathLength(graph);
	cout << shortest << endl;
}