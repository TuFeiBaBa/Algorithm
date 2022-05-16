#include <vector>
#include <iostream>
using namespace std;

/**
*
* ��������II��https://leetcode.cn/problems/redundant-connection-ii/
* ���ӱ�һ���γɻ��𣿲�һ����ע�����������ͼ����������ͼ�����£�������ӱ���[2->3]����Ȼ�޷��γɻ���
*		1
*	 /	  \
*	2	   3
* ����Ŀ�������ӣ��кβ�ͬ����������������ͼ����������ͼ�����ӱ߱ض��γɻ������Ǹ���������ͼ����һ���л�������ж��֣�
*	�л��޳�ͻ [[1,2],[2,3],[3,1]]		(��ͻ��ָ����Ϊ2���ӽڵ�ָ�򸸽ڵ㣬������Ҳ�У��Ǿ�����ȣ�)
*		1
*	 	  \
*		   2
*		 	 \
*			  3  (���ӱ���[3->1])
*	�л��г�ͻ [[1,2],[2,3],[3,1],[4,2]]
*		4
*	 	  \
*		   2
*		 	 \
*			  3
*				\
*				 1	(���ӱ���[1->2])
*	�޻��г�ͻ [[1,2],[1,3],[2,3]]
*		1
*	 /	  \
*	2	   3	(���ӱ���[2->3])
* �ⷨ��
* ��������
*	�����ԣ��۾ݲ���֣������ã����ҽ���һ������ͼ���޻�ͼʱ�������ܽ����������򡣻�����������ͼ�л���BFS�󣬶��л����ڽڵ㣩��
*	���ã���Ч�ʲ��ߣ����������ؽⷨ��Ҫ�������������1.ĳ���ڵ�x���Ϊ2��2.ͼ�д������򻷡�ͬʱȷ����������"������"ֻ��һ�������ԡ�
*
* ���鼯�������ٷ��ֻ�����find(x)==find(y)
*
*/
class Solution {
private:
	int find(vector<int>& parent, int x) {
		if (x != parent[x]) {
			parent[x] = find(parent, parent[x]);
		}
		return parent[x];
	}

	bool isConnect(vector<int>& parent, int x, int y) {
		return find(parent, x) == find(parent, y);
	}

	void merge(vector<int>& parent, int x, int y) {
		int rootX = find(parent, x);
		int rootY = find(parent, y);
		parent[rootY] = rootX;
	}

public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1);
		vector<int> directParent(n + 1);
		int confict = -1;
		int cycle = -1;
		for (int i = 0; i < parent.size(); i++) {
			parent[i] = i;
			directParent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			int node1 = edges[i][0];
			int node2 = edges[i][1];
			if (directParent[node2] != node2) {
				confict = i;
			}
			else {
				directParent[node2] = node1;
				if (!isConnect(parent, node1, node2)) {
					merge(parent, node1, node2);
				}
				else {
					cycle = i;
				}
			}
		}

		//�������������У�ͬһ���߲�����ͬʱ����Ϊ���³�ͻ�ıߺ͵��»�·���ֵıߡ�
		//�ڱ���ͼ�е����б�֮�󣬸����Ƿ���ڵ��³�ͻ�ıߺ͵��»�·���ֵıߣ��õ����ӵıߡ�
		// 
		//���û�е��³�ͻ�ıߣ�˵�����ӵı�һ�����»�·���֣��������ڻ�·�е����һ�������ʵ��ıߣ���˸��ӵı߼�Ϊ���»�·���ֵıߡ�
		//
		//����е��³�ͻ�ıߣ���������Ϊ[u, v][u, v]������������ָ�� vv����һ����Ϊ[\textit{ parent } [v] , v][parent[v], v]����Ҫͨ���ж��Ƿ��е��»�·�ı߾����������Ǹ��ӵıߡ�
		//		����е��»�·�ıߣ��򸽼ӵı߲�������[u, v][u, v]����Ϊ[u, v][u, v] �Ѿ�����Ϊ���³�ͻ�ıߣ������ܱ���Ϊ���»�·���ֵıߣ�����˸��ӵı���[\textit{ parent } [v] , v][parent[v], v]��
		//		���û�е��»�·�ıߣ��򸽼ӵı��Ǻ󱻷��ʵ���ָ�� vv �ıߣ���˸��ӵı���[u, v][u, v]��
		if (confict < 0) {
			return edges[cycle];
		}
		else {
			
			//����Ĵ�����ʵ����ȫ��~��ԭͼ~���л��޳�ͻ���л��г�ͻ���޻��г�ͻ��������
			//���磬�����������飬��ȫ��ʾ��ͬһ���л��г�ͻ��ͼ����һ��cycle<0��һ����֮��
			//[[3, 1]��[2, 1], [4, 2], [1, 4]]
			//[[2, 1], [3, 1], [4, 2], [1, 4]]
			if (cycle < 0) {
				return edges[confict];
			}
			else {
				return vector<int>{directParent[edges[confict][1]], edges[confict][1]};
			}
		}

		return vector<int>{};
	}
};

int main() {
	Solution su;
	vector<vector<int>> edges{ {3,1},{2,1},{4,2},{1,4} };
	vector<int> extraEdge = su.findRedundantDirectedConnection(edges);
	cout << "(" << extraEdge[0] << "," << extraEdge[1] << ")" << endl;
}