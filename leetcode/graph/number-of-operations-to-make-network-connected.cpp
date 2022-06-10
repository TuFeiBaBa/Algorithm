#include <vector>
using namespace std;
/*
* ��ͨ����Ĳ���������https://leetcode.cn/problems/number-of-operations-to-make-network-connected/
*
* ˼·��
*	1.ʲôʱ���޷�ʹ�������綼��ͨ��2����Ҫ��ͨ��������Ҫ1���ߡ�3����������Ҫ2���ߡ��Դ����ƣ�n���㣬������Ҫn - 1���ߡ�
*	2.��ô������Ҫ�������߲���ʹ�������綼��ͨ��ͬ˼·1��ÿ����ͨ�����缯��������Ϊһ����ͨ������������Ϊһ���㡣
*	  ��������ͨ����������һ��ֻ��Ҫһ�����ߡ�������Ҫ����...
*
*/
class Solution {
private:
	vector<int> parent;
	vector<int> weight;
	int count;

	int find(int x) {
		if (x != parent[x]) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
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
		count--;
	}

public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (n > connections.size() + 1) return -1;
		parent = vector<int>(n);
		weight = vector<int>(n, 1);
		count = n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < connections.size(); i++) {
			merge(connections[i][0], connections[i][1]);
		}
		return count - 1;
	}
};

int main() {

}