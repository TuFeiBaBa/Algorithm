#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
* 等式方程的可满足性：  https://leetcode.cn/problems/satisfiability-of-equality-equations/
*
* { "a!=b", "b!=c", "c!=a" }，和种类并查集不一样，敌人的敌人，不一定是朋友。
*/
//class Solution {
//private:
//	vector<int> parent = vector<int>(52, -1);
//	vector<int> weight = vector<int>(52, 1);
//	int find(int x) {
//		if (x != parent[x]) {
//			parent[x] = find(parent[x]);
//		}
//		return parent[x];
//	}
//
//	bool isConnect(int x, int y) {
//		return find(x) == find(y);
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
//	}
//
//public:
//	bool equationsPossible(vector<string>& equations) {
//		for (int i = 26; i < 52; i++) {
//			parent[i] = i;
//		}
//		for (int i = 0; i < equations.size(); i++) {
//			int x = equations[i][0] - 'a';
//			int y = equations[i][3] - 'a';
//			//["a!=a"]
//			if (x == y) {
//				if (equations[i][1] == '=') {
//					continue;
//				}
//				else {
//					return false;
//				}
//			}
//			if (parent[x] == -1 || parent[y] == -1) {
//				if (parent[x] == -1) {
//					parent[x] = x;
//				}
//				if (parent[y] == -1) {
//					parent[y] = y;
//				}
//				if (equations[i][1] == '=') {
//					merge(x, y);
//				}
//				else {
//					//无法处理{ "a!=b", "b!=c", "c!=a" }
//					//如果按这种方式处理，最后有parent[a] = 'b' + 1;,parent[c] = 'b' + 1,显然不对。在这里，敌人的敌人并不是朋友
//					merge(x, y + 26);
//					merge(x + 26, y);
//				}
//
//			}
//			else {
//				bool b = isConnect(x, y);
//				if (equations[i][1] == '=' && !b) {
//					return false;
//				}
//				else if (equations[i][1] != '=' && b) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//};

class Solution {
private:
	vector<int> parent = vector<int>(26);
	vector<int> weight = vector<int>(26, 1);
	int find(int x) {
		if (x != parent[x]) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	bool isConnect(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int x, int y) {
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
	}

public:
	bool equationsPossible(vector<string>& equations) {
		for (int i = 0; i < 26; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < equations.size(); i++) {
			int x = equations[i][0] - 'a';
			int y = equations[i][3] - 'a';
			if (equations[i][1] == '=') {
				merge(x, y);
			}
		}
		for (int i = 0; i < equations.size(); i++) {
			int x = equations[i][0] - 'a';
			int y = equations[i][3] - 'a';
			if (equations[i][1] == '!') {
				if (isConnect(x, y)) {
					return false;
				}
			}
		}
		//c++忘了写return，vs检测不出来..
		return true;
	}
};

int main() {
	vector<string> equations{ "a!=b", "b!=c", "c!=a" };
	Solution su;
	int b = su.equationsPossible(equations);
	cout << b << endl;
}