#include <vector>
#include <queue>
using namespace std;
/*
* 验证二叉树：https://leetcode.cn/problems/validate-binary-tree-nodes/
* 
* 二叉树的特点：
*	1.最多只有两个子节点(leftChild、rightChild这样的表示，隐式满足了这一点)
*	2.无向无环（从题目来看，理解成有向无环且所有的点入度不会大于1更合适）
*	3.只有一个根节点：入度为0
*
* 官解：https://leetcode.cn/problems/validate-binary-tree-nodes/solution/yan-zheng-er-cha-shu-by-leetcode-solution/
*
* 并查集解（结合题意，没有路径压缩和按轶合并）：https://leetcode.cn/problems/validate-binary-tree-nodes/solution/by-fujunwei-inub/
*
* 上述两种解法，均优于下方代码。主要是没有额外再构建图？
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
		// //不可能有两个根节点
		// if (q.size() > 1) return false;

		//上述代码解决不了有向无环：
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

		//上述代码与前面的类似。
		//增加if (in[i] == 2) return false;是为了解决有向无环
		//增加if (zeroNum == 0) return false;是为了解决有环。但是由于不能保证连通性，所以处理不了下面的情况：
		//n = 4
		//leftChild = [1, 0, 3, -1]
		//rightChild = [-1, -1, -1, -1]


		for (int i = 0; i < n; i++) {
			if (in[i] == 0) q.push(i);
			if (in[i] == 2) return false;
			//不可能有两个根节点
			if (q.size() > 1) return false;
		}
		int num = 0;
		//用拓扑排序验证树是否有环
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