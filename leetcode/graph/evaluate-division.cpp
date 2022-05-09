#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
/**
* 除法求值：https://leetcode.cn/problems/evaluate-division/
* 并查集：
*	由于 变量之间的倍数关系具有传递性，处理有传递性关系的问题，可以使用「并查集」，
  我们需要在并查集的「合并」与「查询」操作中 维护这些变量之间的倍数关系。

  并查集如何排除掉没有关系的变量？没有关系的变量经过union后，不就有关系了？
	两个没有关系的变量，不应该进行union操作。
*/
class UnionFind {
public:

	UnionFind(int n) {
		cnt = n;
		parent = vector<int>(n);
		weight = vector<double>(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			weight[i] = 1.0;
		}
	}

	int count() {
		return cnt;
	}

	//int find(int x) {
	//	//错误的路径压缩写法
	//	/*while (x != parent[x]) {
	//		parent[x] = parent[parent[x]];
	//		x = parent[x];
	//	}*/
	//	//非递归式路径压缩
	//	int root = x;
	//	while (root != parent[root]) {
	//		root = parent[root];
	//	}
	//	while (x != root) {
	//		int newx = parent[x];
	//		parent[x] = root;
	//		x = newx;
	//	}
	//	return x;
	//}

	//传值不应该传string& a。用int来做映射。查询也更快。
	int find(int x) {
		int root = x;
		double base = 1;
		while (root != parent[root]) {
			base *= weight[root];
			root = parent[root];
		}
		while (x != root) {
			//写成了int w，导致很隐秘的错误
			double w = weight[x];
			weight[x] = base;
			int newx = parent[x];
			parent[x] = root;
			base /= w;
			x = newx;
		}
		return x;
	}

	//递归式
	//int find(int x) {
	//	if (x != parent[x]) {
	//		int origin = parent[x];
	//		parent[x] = find(parent[x]);
	//		weight[x] *= weight[origin];
	//	}
	//	return parent[x];
	//}



	double isConnect(int x, int y) {
		int a = find(x);
		int b = find(y);
		if (a == b) return weight[x] / weight[y];
		else return -1;
	}

	void unionFun(int x, int y, double value) {
		int a = find(x);
		int b = find(y);
		if (a == b) return;
		parent[a] = b;
		//这个推导完全不会...
		weight[a] = weight[y] * value / weight[x];
	}

private:
	int cnt;
	vector<int> parent;
	vector<double> weight;
};

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, int> map;
		//equations.size() * 2 是为了确保数组容量足够大
		UnionFind uf(equations.size() * 2);
		int id = 0;
		for (int i = 0; i < equations.size(); i++) {
			vector<string>& equat = equations[i];
			string& s1 = equat[0];
			string& s2 = equat[1];
			if (map.count(s1) == 0) {
				map[s1] = id;
				id++;
			}
			if (map.count(s2) == 0) {
				map[s2] = id;
				id++;
			}
			uf.unionFun(map[s1], map[s2], values[i]);
		}

		vector<double> result;
		for (int i = 0; i < queries.size(); i++) {
			vector<string>& query = queries[i];
			string& s1 = query[0];
			string& s2 = query[1];
			if (map.count(s1) == 0 || map.count(s2) == 0) {
				result.emplace_back(-1);
				continue;
			}
			result.emplace_back(uf.isConnect(map[s1], map[s2]));
		}
		return result;
	}
};

int main() {
	Solution su;
	/*vector<vector<string>> equations{ {"a","b"},{"b","c" } };
	vector<double> values{ 2.0,3.0 };
	vector<vector<string>> quueries{ {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };*/

	vector<vector<string>> equations{ {"a", "b"} ,{"b", "c"} };
	vector<double> values{ 1.5, 2.5 };
	vector<vector<string>> quueries{ {"a","c"}, {"c","b"} };
	vector<double> res = su.calcEquation(equations, values, quueries);

	/*vector<vector<string>> equations{ {"x1", "x2"} ,{"x2", "x3"},{"x3", "x4"},{"x4", "x5" } };
	vector<double> values{ 3.0, 4.0, 5.0, 6.0 };
	vector<vector<string>> quueries{ {"x1","x5"} };
	vector<double> res = su.calcEquation(equations, values, quueries);*/
	for_each(res.begin(), res.end(), [](const double i) {cout << i << " "; });
}