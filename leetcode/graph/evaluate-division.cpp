#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
/**
* ������ֵ��https://leetcode.cn/problems/evaluate-division/
* ���鼯��
*	���� ����֮��ı�����ϵ���д����ԣ������д����Թ�ϵ�����⣬����ʹ�á����鼯����
  ������Ҫ�ڲ��鼯�ġ��ϲ����롸��ѯ�������� ά����Щ����֮��ı�����ϵ��

  ���鼯����ų���û�й�ϵ�ı�����û�й�ϵ�ı�������union�󣬲����й�ϵ�ˣ�
	����û�й�ϵ�ı�������Ӧ�ý���union������
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
	//	//�����·��ѹ��д��
	//	/*while (x != parent[x]) {
	//		parent[x] = parent[parent[x]];
	//		x = parent[x];
	//	}*/
	//	//�ǵݹ�ʽ·��ѹ��
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

	//��ֵ��Ӧ�ô�string& a����int����ӳ�䡣��ѯҲ���졣
	int find(int x) {
		int root = x;
		double base = 1;
		while (root != parent[root]) {
			base *= weight[root];
			root = parent[root];
		}
		while (x != root) {
			//д����int w�����º����صĴ���
			double w = weight[x];
			weight[x] = base;
			int newx = parent[x];
			parent[x] = root;
			base /= w;
			x = newx;
		}
		return x;
	}

	//�ݹ�ʽ
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
		//����Ƶ���ȫ����...
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
		//equations.size() * 2 ��Ϊ��ȷ�����������㹻��
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