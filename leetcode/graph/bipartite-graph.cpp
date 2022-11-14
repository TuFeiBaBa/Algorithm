#include <vector>
#include <numeric>
#include <queue>

using namespace std;
//class Solution {
//private:
//	vector<int> parent;
//	vector<int> weight;
//	int count;
//
//	int find(int x) {
//		if (parent[x] != x) {
//			parent[x] = find(parent[x]);
//		}
//		return parent[x];
//	}
//
//	void merge(int x, int y) {
//		int rootX = find(x);
//		int rootY = find(y);
//		if (rootX == rootY) return;
//		if (weight[rootX] > weight[rootY]) {
//			parent[rootY] = rootX;
//			weight[rootX] += weight[rootY];
//		}
//		else {
//			parent[rootX] = rootY;
//			weight[rootY] += weight[rootX];
//		}
//		count--;
//	}
//
//public:
//	bool isBipartite(vector<vector<int>>& graph) {
//		int n = graph.size();
//		count = n;
//		weight = vector<int>(n, 1);
//		parent = vector<int>(n);
//		iota(parent.begin(), parent.end(), 0);
//		for (int i = 0; i < n; i++) {
//			for (int j : graph[i]) {
//				merge(i, j);
//			}
//		}
//		return count == 2;
//	}
//};

//class Solution {
//public:
//    bool isBipartite(vector<vector<int>>& graph) {
//        int n = graph.size();
//        vector<int> in(n);
//        for (int i = 0; i < n; i++) {
//            for (int j : graph[i]) {
//                in[i]++;
//            }
//        }
//        for (int i : in) {
//            if (i != 2) return false;
//        }
//        return true;
//    }
//};

/*
* 二分图 https://leetcode.cn/problems/vEAB3K/description/
* 
* 一开始没看题，以为是要求判断，图是否刚好是两个连通图，直接用了并查集...
* 然后又以为只要判断每个节点的入度是否为2..
* 
* [[4,1],[0,2],[1,3],[2,4],[3,0]] 五个节点刚好连成一个环，但不是二分图
* [[1],[0,3],[3],[1,2]]           无环：不是每个节点的入度都是2
* [[3],[2],[1],[0]]				  非连通图
* 
*/
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		//used[i] == 0表示节点未访问过
		//used[i] == 1表示节点是颜色一
		//used[i] == -1表示节点是颜色二
		vector<int> used(n);
		//int nums = 0;
		for (int i = 0; i < n; i++) {
			//错误：used[i] == -1时，判断也会是true
			//if (!used[i])continue;
			if (used[i] != 0) continue;
			queue<int> q;
			q.push(i);
			used[i] = 1;
			//nums++;
			while (!q.empty()) {
				int begin = q.front();
				q.pop();
				for (int end : graph[begin]) {
					if (used[end] == 0) {
						used[end] = -used[begin];
						//nums++;
						q.push(end);
					}
					else if (used[end] == used[begin]) {
						return false;
					}
				}
			}
		}
		//return nums == n;
		//能到这里，肯定所有的顶点都遍历了一次，所以nums是多余的判断
		return true;
	}
};

int main() {

}