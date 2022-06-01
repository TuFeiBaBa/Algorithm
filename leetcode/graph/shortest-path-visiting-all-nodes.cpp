#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;
/**
* �������нڵ�����·����https://leetcode.cn/problems/shortest-path-visiting-all-nodes/
*
* ˼·��
*	1.�㷨��ѡ���л����յ㡢��㲻ȷ�������·���볣��Ĳ�һ�����߿��ظ�������
*	  �������������л������ؼ�·�����л�����Dijkstra���ǵ�Դ�ұ߿��ظ���������Bellman-Ford���ǵ�Դ�ұ߿��ظ����������㷨��������
*	2.�Ӳ�ͬ�Ľڵ㿪ʼ���γɵ����·�������ܲ�ͬ������Ч�ֶΣ�����ȷ��������������ԣ�ֻ�ܱ����س������е������
*	3.�����Ż�һ�±����⣺
*		0		 1
*		 \		/
*		  \	   /
*			2
*	  ���ϣ��������ľֲ�ͼ���ڵ�2���滹��һ�ѽڵ�δ����������
*	  ����ӽڵ�0��ʼ��·��Ϊ[0,2,1,2]���ӽڵ�1��ʼ��·��Ϊ[1,2,0,2]����������ʼ����������Ľڵ㣬·���ĳ�������ͬ�ģ�������ȫ���Ժϲ���
*
*	  ���⣺��û�о����ڵ�һ������·�����Ȳ�һ���������
*	  ���С����磬��2��ʼ�Ļ�����ʼ·��Ϊ[2��0��2��1��2]�����Ǿ�����[0,1,2]�����ڵ㣬��·��������Ȼ��������������ʼ�����
*
*	  ���⣺��δ������������
*	  ��ʹ�ù��������������ô�������ڵ�[0��1��2]�����ڵ����̵�·������Ȼ���Ƚ�������еȴ���һ�γ��ӡ�����ͬ���ڵ�ģ��ϳ���·����
*	  Ҳ�Ϳ��Ա��ų��������ˡ�
*
*	  ���⣺���ʹ�ü����Ż�������֦���Դӽڵ�0��ʼΪ����·��[0,2,1]�Ѿ������˽ڵ�[0,1,2]�����ڵ㣬����ǵ�������mark���б�ǣ�
*	  0��1��2���Ѿ��ѱ��λ��Ϊ1�ˡ��������������α�ʾ�ظ�����[1��2]�����ߣ��ص��ڵ�2������������
*	  ������seen������������������seen[mark]Ϊtrueʱ��·��mark������·��Ϊ[0,2��1��2]ʱ��mark�Ķ����Ʊ�ʾΪ11100...���Ѿ����ʹ��ˡ�
*	  ��Ȼ��seen�������ṩ����Ϣ���㣬���ֲ������������ע�⣺[0,2,1]��[0,2,1,2]����ͬ���ڣ������Ʊ��λ����11100..����ͬ���ڵ�ǰ���ڵ㲻һ����
*	  ���ԣ���Ҫ���ӵ�ǰ����λ�õ���Ϣ���þ���seen����¼��seen[i][mark]Ϊtrueʱ����ʾ�������ڵ�iʱ��·��mark�Ѿ����ʹ�������Ҫ�ظ���Ӹ���������ڼ�֦����
*
* ʱ�临�Ӷȣ�
*	  ����Ĺ������������ʱ�临�Ӷ�Ϊ O(n + m)������ n �� m �ֱ��ʾͼ�Ľڵ����ͱ����������������� mask ��һά�ȣ���ȡֵ��ΧΪ [0, 2^n)��
*	  ��˿��Կ����ǽ����� 2^n �γ���Ĺ���������������� m �ķ�Χû����ʽ��������������Ϊ��ȫͼ��������Ͽ�֪����n(n - 1)/2���ߣ�
*	  ������ m = O(n^2)�������ʱ�临�Ӷ�ΪO(n^2 * 2^n)
*
* �ռ临�Ӷȣ�O(n * 2^n)����Ϊseen��Ҫʹ�õĿռ�
*/
//class Solution {
//public:
//	int shortestPathLength(vector<vector<int>>& graph) {
//		int n = graph.size();
//		//mark�Ķ�������ʽ��һ����nλ����ѡֵΪ0��1
//		//��ʵ�����ظ����У�U(m,n) = n^m = 2^n
//		//2^n,��ʵ����1 << n
//		vector<vector<bool>> seen(n, vector<bool>(1 << n));
//		queue<tuple<int, int, int>> q;
//		for (int i = 0; i < graph.size(); i++) {
//			q.emplace(i, 1 << i, 0);
//		}
//		int full = (1 << n) - 1;
//		while (!q.empty()) {
//			tuple<int, int, int>& t = q.front();
//			//���ͷ���Դ������addresssanitizer heap-use-after-free
//			//q.pop();
//			int i = get<0>(t);
//			int mark = get<1>(t);
//			int d = get<2>(t);
//			q.pop();
//			if (mark == full) return d;
//			for (int j : graph[i]) {
//				//����Ӧ���Ƕ����Ʋ���..�ǵü�����..
//				//int markJ = mark + (1 << j);
//				int markJ = mark | (1 << j);
//				//������return��Ӧ�ø��á�����ʱ����ʹ��nΪ1������������������Ǻ���return 0��Ҳ�ܸ���
//				//if (markJ == full) return d + 1;
//				if (!seen[j][markJ]) {
//					seen[j][markJ] = true;
//					q.emplace(j, markJ, d + 1);
//				}
//			}
//		}
//		return 0;
//	}
//};

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> d(n, vector<int>(n, n + 1));
		for (int i = 0; i < n; ++i) {
			for (int j : graph[i]) {
				d[i][j] = 1;
			}
		}
		// ʹ�� floyd �㷨Ԥ��������е��֮������·������
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
		for (int mask = 1; mask < (1 << n); ++mask) {
			//��� mask ֻ����һ�� 1���� mask �� 2 ����
			if ((mask & (mask - 1)) == 0) {
				//C++ __builtin_ϵ�к���:https://blog.csdn.net/yandaoqiusheng/article/details/102920785
				int u = __builtin_ctz(mask);
				//���ڿ��Խ��������Ϊ�����������Խ���Щ������̾��루����������Ϊ 0
				//Ҳ�����ڱ���mask֮ǰ��ͨ�����д�����г�ʼ��
				//for (int i = 0; i < n; i++) f[i][1 << i] = 0;

				//�������ʼ�������ᵼ�����⣿
				//���ᡣ��������̬�滮�����У�����u-v��һ���ߡ�v����Ŵ���u��f[u][mask]�е�mask�ǲ���ʹ�õ�v�ġ�
				//f[v][mask]�Ż�ʹ�õ�u�������Ƕ����룬u-v������ġ������f[v][mask]���Ǽ���u-v�����·����
				f[u][mask] = 0;
			}
			else {
				for (int u = 0; u < n; ++u) {
					if (mask & (1 << u)) {
						for (int v = 0; v < n; ++v) {
							if ((mask & (1 << v)) && u != v) {
								f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] + d[v][u]);
							}
						}
					}
				}
			}
		}

		int ans = INT_MAX;
		for (int u = 0; u < n; ++u) {
			ans = min(ans, f[u][(1 << n) - 1]);
		}
		return ans;
	}
};

int main() {
	//vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	Solution su;
	int shortest = su.shortestPathLength(graph);
	cout << shortest << endl;
}