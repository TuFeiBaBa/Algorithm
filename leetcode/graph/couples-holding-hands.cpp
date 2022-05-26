#include <vector>
#include <iostream>

using namespace std;
/**
* ����ǣ�֣�https://leetcode.cn/problems/couples-holding-hands/
*
* ���� row[i]������/Ů����Ϊ row[i] ^ 1 (������㣬��ʵֻ�Ǹı���row[i]�������Ҷ˵�ȡֵ)
* (ע�⣺�ô������۵�ǰ��ֵ������ż��������ֵ�������Ҷ���0��1������ͨ��+��-����Ҫ���жϵ�ǰ������ż������������+��-1)
*
* ���鼯��https://leetcode.cn/problems/couples-holding-hands/solution/qing-lu-qian-shou-by-leetcode-gl1c/
* ����˼·����������� k �������γ��˴��󻷣���Ҫ���� k - 1 �β���������ǣ�֡�
* ��������ת���� n / 2 �������У��ж��ٸ������Ļ���
*
* ̰�ģ���֤���ɲο���https://leetcode.cn/problems/couples-holding-hands/solution/liang-chong-100-de-jie-fa-bing-cha-ji-ta-26a6/)
*	̰��֤����˼·���������־ֲ������Ȼ��Ӿֲ��Ƶ�ȫ��
*
* �������������https://leetcode.cn/problems/couples-holding-hands/solution/qing-lu-qian-shou-by-leetcode-solution-bvzr/
* ����˼·������ƥ���row[i]��row[i + 1]����Ϊ����ͼ�ϵ���ͨ�������ڵ㡣Ȼ����BFS����ͼ���������Ƕ����ͨͼ��ɵ�ͼ������Ҫ����ÿ�����ܵ���㣬����BFS��
*/
class UnionFind {
private:
	vector<int> parent;
	vector<int> weight;
	int count;

public:
	UnionFind(int n) {
		count = n;
		parent = vector<int>(n);
		weight = vector<int>(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			weight[i] = 1;
		}
	}

	int getCount() {
		return count;
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;
		if (weight[x] > weight[y]) {
			//TODO ��Ҫÿ�ζ�д��x��y...
			parent[rootY] = rootX;
			weight[rootX] += weight[rootY];
		}
		else {
			parent[rootX] = rootY;
			weight[rootY] += weight[rootX];
		}
		count--;
	}
};

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		UnionFind uf(n);
		for (int i = 0; i < row.size(); i += 2) {
			uf.merge(row[i] / 2, row[i + 1] / 2);
		}
		return n - uf.getCount();
	}
};

int main() {
	Solution su;
	vector<int> row{ 5,4,2,6,3,1,0,7 };
	int ret = su.minSwapsCouples(row);
	cout << ret << endl;

}