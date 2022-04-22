#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
private:
	//	void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dist, vector<int>& parent) {
	//		for (int n : graph[node]) {
	//			if (!visited[n]) {
	//				dist[n] = dist[node] + 1;
	//				visited[n] = true;
	//				parent[n] = node;
	//				dfs(n, graph, visited, dist, parent);
	//			}
	//		}
	//	}
	//
	//	int findLongestNode(int n, vector <vector<int>>& graph, vector<int>& parent) {
	//		vector<bool> visited(graph.size());
	//		vector<int> dist(graph.size(), -1);
	//		visited[n] = true;
	//		dfs(n, graph, visited, dist, parent);
	//
	//		int maxPath = -1;
	//		int node = -1;
	//		for (int i = 0; i < dist.size(); i++) {
	//			if (maxPath < dist[i]) {
	//				maxPath = dist[i];
	//				node = i;
	//			}
	//		}
	//		return node;
	//	}
	//
	//public:
	//	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	//		vector<vector<int>> graph(n);
	//		//用i < n是错误的
	//		for (int i = 0; i < edges.size(); i++) {
	//			graph[edges[i][0]].push_back(edges[i][1]);
	//			graph[edges[i][1]].push_back(edges[i][0]);
	//		}
	//
	//		vector<int> parent(n, -1);
	//		int x = findLongestNode(0, graph, parent);
	//		int y = findLongestNode(x, graph, parent);
	//		vector<int> paths;
	//		parent[x] = -1;
	//		while (y != -1) {
	//			paths.emplace_back(parent[y]);
	//			y = parent[y];
	//		}
	//		int m = paths.size();
	//		if (m % 2 == 0) {
	//			return { paths[m / 2 - 1], paths[m / 2] };
	//		}
	//		else {
	//			return { paths[m / 2] };
	//		}
	//	}
private:
	/*
	* parent不要传对象，要传引用或指针。否则传进来的不是原对象，修改无效。
	*/
	int bfs(int root, vector<vector<int>>& graph, vector<int>& parent) {
		queue<int> q;
		vector<bool> visited(graph.size());
		visited[root] = true;
		q.push(root);
		int tail_node = 0;
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			tail_node = n;
			for (int node : graph[n]) {
				if (!visited[node]) {
					visited[node] = true;
					parent[node] = n;
					q.push(node);
				}
				//tail_node = node;
			}
		}
		return tail_node;
	}
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		//n和edges.size()是不一致的
		vector<vector<int>> graph(n);
		vector<int> parent(n, -1);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		int x = bfs(0, graph, parent);
		int y = bfs(x, graph, parent);
		vector<int> paths;
		parent[x] = -1;
		while (y != -1) {
			paths.push_back(y);
			y = parent[y];
		}
		int m = paths.size();
		if (m % 2 == 0) {
			return { paths[m / 2 - 1], paths[m / 2] };
		}
		else {
			return { paths[m / 2] };
		}
	}
};

int main() {
	Solution su;
	vector<vector<int>> input{ {1, 0}, { 1, 2 }, { 1, 3 } };
	vector<int> res = su.findMinHeightTrees(4, input);
	for_each(res.begin(), res.end(), [](const int i) {cout << i << " "; });
}