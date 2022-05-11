/**
* �������ӣ�https://leetcode.cn/problems/redundant-connection/
*
* ����˼·������ͼ��Ȼ���ڹ���ͼ�Ĺ����У��ҵ���������������map���жϱ���edges�г��ֵ�˳������"�����ֵı�"���Ҫ�󡣣�Ӧ��Ҳ�ܽ⣬���ǹ��ڸ��ӣ�ʱ�临�Ӷ�Ҳ�������ţ�
*
* ��ȷ˼·�����鼯
* 1.����edges���ж���ɱߵ������ڵ㣬�Ƿ�����ͨ������
*    1.���ǣ��ϲ�����
*    2.�ǣ����Ǿ��Ǹ��ӱ�
*
* ���鼯�����������������"�����ֵı�"���Ҫ��?
* ����edges���鱾����ǹ���ͼ�Ĺ��̣�������һ���ߵ���������ͨʱ,˵��������һ��·���������������㡣
* ����ټ��������߾ͻ��ɻ���Ȼ�������߸պ����������������������һ���ߣ�����"�����ֵı�"���������
*
*/
#include <vector>
using namespace std;
class Solution {
private:
	int find(vector<int>& parent, int x) {
		if (x != parent[x]) {
			parent[x] = find(parent, parent[x]);
		}
		return parent[x];
	}

	void merge(vector<int>& parent, int x, int y) {
		int rootX = find(parent, x);
		int rootY = find(parent, y);
		parent[rootX] = rootY;
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1);
		for (int i = 0; i < n + 1; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < edges.size(); i++) {
			if (find(parent, edges[i][0]) != find(parent, edges[i][1])) {
				merge(parent, edges[i][0], edges[i][1]);
			}
			else {
				return edges[i];
			}
		}
		return vector<int>{};
	}
};


int main() {

}