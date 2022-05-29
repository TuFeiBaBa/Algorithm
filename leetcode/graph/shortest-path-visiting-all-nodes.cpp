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
*/
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		//mark�Ķ�������ʽ��һ����nλ����ѡֵΪ0��1
		//��ʵ�����ظ����У�U(m,n) = n^m = 2^n
		//2^n,��ʵ����1 << n
		vector<vector<bool>> seen(n, vector<bool>(1 << n));
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < graph.size(); i++) {
			q.emplace(i, 1 << i, 0);
		}
		int full = (1 << n) - 1;
		while (!q.empty()) {
			tuple<int, int, int>& t = q.front();
			//���ͷ���Դ������addresssanitizer heap-use-after-free
			//q.pop();
			int i = get<0>(t);
			int mark = get<1>(t);
			int d = get<2>(t);
			q.pop();
			if (mark == full) return d;
			for (int j : graph[i]) {
				//int markJ = mark + (1 << j);
				int markJ = mark | (1 << j);
				if (!seen[j][markJ]) {
					seen[j][markJ] = true;
					q.emplace(j, markJ, d + 1);
				}
			}
		}
		return 0;
	}
};

int main() {
	//vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	vector <vector<int>> graph{ {1, 2, 3}, { 0}, { 0}, { 0} };
	Solution su;
	int shortest = su.shortestPathLength(graph);
	cout << shortest << endl;
}