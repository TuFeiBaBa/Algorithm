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
*/
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		//mark的二进制形式，一共有n位，可选值为0、1
		//其实就是重复排列，U(m,n) = n^m = 2^n
		//2^n,其实就是1 << n
		vector<vector<bool>> seen(n, vector<bool>(1 << n));
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < graph.size(); i++) {
			q.emplace(i, 1 << i, 0);
		}
		int full = (1 << n) - 1;
		while (!q.empty()) {
			tuple<int, int, int>& t = q.front();
			//会释放资源，导致addresssanitizer heap-use-after-free
			//q.pop();
			int i = get<0>(t);
			int mark = get<1>(t);
			int d = get<2>(t);
			q.pop();
			if (mark == full) return d;
			for (int j : graph[i]) {
				//int markJ = mark + (1 << j);
				int markJ = mark | (1 << j);
				if (!seen[j][markJ]) {
					seen[j][markJ] = true;
					q.emplace(j, markJ, d + 1);
				}
			}
		}
		return 0;
	}
};

int main() {
	//vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	Solution su;
	int shortest = su.shortestPathLength(graph);
	cout << shortest << endl;
}