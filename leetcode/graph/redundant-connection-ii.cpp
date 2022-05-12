#include <vector>
#include <iostream>
using namespace std;

/**
*
* 冗余连接II：https://leetcode.cn/problems/redundant-connection-ii/
* 附加边一定形成环吗？不一定，注意这个是有向图，不是无向图，示例一就没有形成环。
*
* 与题目冗余连接，有何不同？冗余连接是无向图，不是有向图，附加边必定形成环，但是该题是有向图，不一定有环，情况有多种：
*	有环无冲突 [[1,2],[2,3],[3,1]]		(冲突是指出度为2（子节点指向父节点，反着来也行，那就是入度）)
*	有环有冲突 [[1,2],[2,3],[3,1],[4,2]]
*	无环有冲突 [[1,2],[1,3],[2,3]]
*
* 解法：
* 拓扑排序：
*	（不对，论据不充分）不可用：当且仅当一幅有向图是无环图时，它才能进行拓扑排序。或者用来检测该图有环（BFS后，队列还存在节点）。
*	可用，但效率不高：题解区有相关解法，要处理两种情况：1.某个节点x入度为2，2.图中存在有向环。同时确定哪条边是"最后出现"只能一个个尝试。
*
* 并查集：
*
*/
class Solution {
private:
	int find(vector<int>& parent, int x) {
		if (x != parent[x]) {
			parent[x] = find(parent, parent[x]);
		}
		return parent[x];
	}

	bool isConnect(vector<int>& parent, int x, int y) {
		return find(parent, x) == find(parent, y);
	}

	void merge(vector<int>& parent, int x, int y) {
		int rootX = find(parent, x);
		int rootY = find(parent, y);
		parent[rootY] = rootX;
	}

public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1);
		vector<int> directParent(n + 1);
		int confict = -1;
		int cycle = -1;
		for (int i = 0; i < parent.size(); i++) {
			parent[i] = i;
			directParent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			int node1 = edges[i][0];
			int node2 = edges[i][1];
			if (directParent[node2] != node2) {
				confict = i;
			}
			else {
				directParent[node2] = node1;
				if (!isConnect(parent, node1, node2)) {
					merge(parent, node1, node2);
				}
				else {
					cycle = i;
				}
			}
		}

		if (confict < 0) {
			return edges[confict];
		}
		else {
			//上述遍历操作中，同一条边不可能同时被记为导致冲突的边和导致环路出现的边。
			
			//这里的处理，其实不完全是~按原图~的有环无冲突、有环有冲突、无环有冲突来分析的
			//比如，下面两组数组，完全表示是同一幅有环有冲突的图，但一个cycle<0，一个则反之：
			//[[3, 1]，[2, 1], [4, 2], [1, 4]]
			//[[2, 1], [3, 1], [4, 2], [1, 4]]
			if (cycle < 0) {
				return edges[confict];
			}
			else {
				return vector<int>{directParent[edges[confict][1]], edges[confict][1]};
			}
		}

		return vector<int>{};
	}
};

int main() {
	Solution su;
	vector<vector<int>> edges{ {3,1},{2,1},{4,2},{1,4} };
	vector<int> extraEdge = su.findRedundantDirectedConnection(edges);
	cout << "(" << extraEdge[0] << "," << extraEdge[1] << ")" << endl;
}