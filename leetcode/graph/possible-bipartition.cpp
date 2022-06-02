#include <vector>

using namespace std;
/**
* ���ܵĶ��ַ�:https://leetcode.cn/problems/possible-bipartition/
* 
* ���ಢ�鼯:https://zhuanlan.zhihu.com/p/97813717
* 
* ʱ�临�Ӷȣ��ο���https://oi-wiki.org/ds/dsu/#_5 (�е㸴�ӣ���ʱ������)
*/
class Solution {
private:
	vector<int> parent;
	int n;
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}
	bool isConnect(int x, int y) {
		return find(x) == find(y);
	}

	/*void merge(int x, int y) {
		int rootX = find(x);
		int rootXn = find(x + n);
		int rootY = find(y);
		int rootYn = find(y + n);

		parent[rootX] = rootYn;
		parent[rootY] = rootXn;
	}*/

	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		parent[rootX] = rootY;
	}

public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		this->n = n;
		parent = vector<int>(2 * n + 1);
		for (int i = 0; i < 2 * n + 1; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < dislikes.size(); i++) {
			int x = dislikes[i][0];
			int y = dislikes[i][1];
			if (isConnect(x, y)) return false;
			//merge(x, y);
			merge(x, y + n);
			merge(y, x + n);
		}
		return true;
	}
};

int main() {

}