#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//class Solution {
//public:
//	int minReorder(int n, vector<vector<int>>& connections) {
//		vector<vector<int>> graph(n, vector<int>(n, 0));
//		for (int i = 0; i < connections.size(); i++) {
//			graph[connections[i][0]][connections[i][1]] = 1;
//			graph[connections[i][1]][connections[i][0]] = 2;
//		}
//
//		queue<int> q;
//		vector<bool> used;
//		q.push(0);
//		int ans = 0;
//		while (!q.empty()) {
//			int top = q.front();
//			q.pop();
//			used[top] = true;
//			//有问题：i并不是顶点，而是代表是否和top顶点有连线、连线朝向
//			for (int i : graph[top]) {
//				if (!graph[top][i] || used[i]) continue;
//				if (graph[top][i] == 1) ans++;
//				q.push(i);
//			}
//		}
//		return ans;
//	}
//};

/*
* 重新规划路线 https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
* 
* 并查集：
* 不合适。并查集的优点是快速查找两者的关系，但是这里，怎么merge是一个问题。0->1、2->1，这里，只要修改0->1的方向就够了。用并查集，
* 很难表述、解决这个问题。
* 
* BFS:
* 认真观察，发现，“路线网形成一颗树”，不考虑方向的话，必然能从节点0，遍历任何其他顶点。只要在遍历过程中，记录方向有问题的路径即可。
*/
class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		//用的是三维，不是二维
		//感觉不用三维也可以，因为构建图用的是邻接矩阵，用vector<Edge>即可，Edge里包括顶点和方向即可。
		vector<vector<vector<int>>> graph(n);
		for (int i = 0; i < connections.size(); i++) {
			graph[connections[i][0]].emplace_back(vector<int>{ connections[i][1], 1 });
			graph[connections[i][1]].emplace_back(vector<int>{ connections[i][0], 2 });
		}

		queue<int> q;
		vector<bool> used(n);
		q.push(0);
		int ans = 0;
		while (!q.empty()) {
			int top = q.front();
			q.pop();
			used[top] = true;
			for (vector<int> v : graph[top]) {
				if (used[v[0]]) continue;
				if (v[1] == 1) ans++;
				q.push(v[0]);
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
	Solution su;
	int nums = su.minReorder(6, connections);
	cout << nums << endl;
}