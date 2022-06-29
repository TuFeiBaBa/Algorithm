#include <vector>
#include <queue>
using namespace std;
/*
* ��֤��������https://leetcode.cn/problems/validate-binary-tree-nodes/
* 
* ���������ص㣺
*	1.���ֻ�������ӽڵ�(leftChild��rightChild�����ı�ʾ����ʽ��������һ��)
*	2.�����޻�������Ŀ���������������޻������еĵ���Ȳ������1�����ʣ�
*	3.ֻ��һ�����ڵ㣺���Ϊ0
*
* �ٽ⣺https://leetcode.cn/problems/validate-binary-tree-nodes/solution/yan-zheng-er-cha-shu-by-leetcode-solution/
*
* ���鼯�⣨������⣬û��·��ѹ���Ͱ���ϲ�����https://leetcode.cn/problems/validate-binary-tree-nodes/solution/by-fujunwei-inub/
*
* �������ֽⷨ���������·����롣��Ҫ��û�ж����ٹ���ͼ��
*/
class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<vector<int>> graph(n);
		vector<int> in(n);
		for (int i = 0; i < n; i++) {
			if (leftChild[i] != -1) {
				graph[i].push_back(leftChild[i]);
				in[leftChild[i]]++;
			}
			if (rightChild[i] != -1) {
				graph[i].push_back(rightChild[i]);
				in[rightChild[i]]++;
			}
		}
		queue<int> q;

		// for (int i = 0; i < n; i++) {
		// 	if (in[i] == 0) q.push(i);
		// }
		// //���������������ڵ�
		// if (q.size() > 1) return false;

		//�������������������޻���
		//4
		//[1, -1, 3, -1]
		//[2, 3, -1, -1]
		//    0
		//   / \
		//  1   2
		//   \	/
		//	  3

		//int zeroNum = 0;
		//for (int i = 0; i < n; i++) {
		//	if (in[i] == 0) zeroNum++;
		//	if (in[i] == 2) return false;
		//	if (zeroNum > 1) return false;
		//}
		//if (zeroNum == 0) return false;

		//����������ǰ������ơ�
		//����if (in[i] == 2) return false;��Ϊ�˽�������޻�
		//����if (zeroNum == 0) return false;��Ϊ�˽���л����������ڲ��ܱ�֤��ͨ�ԣ����Դ���������������
		//n = 4
		//leftChild = [1, 0, 3, -1]
		//rightChild = [-1, -1, -1, -1]


		for (int i = 0; i < n; i++) {
			if (in[i] == 0) q.push(i);
			if (in[i] == 2) return false;
			//���������������ڵ�
			if (q.size() > 1) return false;
		}
		int num = 0;
		//������������֤���Ƿ��л�
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			num++;
			for (int n : graph[node]) {
				in[n]--;
				if (in[n] == 0) {
					q.push(n);
				}
			}
		}
		return num == n;
	}
};

int main() {
	vector<int> left = { 1, -1, 3, -1 };
	vector<int> right = { 2, -1, -1, -1 };
	Solution su;
	su.validateBinaryTreeNodes(4, left, right);
}