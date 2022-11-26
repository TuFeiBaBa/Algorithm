#include <string>

using namespace std;
/*
* ���ݶ����������ַ��� https://leetcode.cn/problems/construct-string-from-binary-tree/description/
* 
* �ǵݹ�ⷨ�ο� https://leetcode.cn/problems/construct-string-from-binary-tree/solutions/1343920/gen-ju-er-cha-shu-chuang-jian-zi-fu-chua-e1af/
*/
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//	string tree2str(TreeNode* root) {
//		if (root == nullptr) {
//			return "";
//		}
//		if (root->left == nullptr && root->right == nullptr) {
//			return to_string(root->val);
//		}
//		if (root->right == nullptr) {
//			return to_string(root->val) + "(" + tree2str(root->left) + ")";
//		}
//		return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
//	}
//};

/*
* ��Ƚ�������Ĵ���,��Ȼ�����,����������ʱ��string����
*/
class Solution {
private:
	string ans;
	void dfs(TreeNode* node) {
		if (node == nullptr) return;
		if (node->left == nullptr && node->right == nullptr) return;
		if (node->left == nullptr) {
			ans += "()";
			ans += "(" + to_string(node->right->val);
			dfs(node->right);
			ans += ")";
		}
		else if (node->right == nullptr) {
			ans += "(" + to_string(node->left->val);
			dfs(node->left);
			ans += ")";
		}
		else {
			ans += "(" + to_string(node->left->val);
			dfs(node->left);
			ans += ")";
			ans += "(" + to_string(node->right->val);
			dfs(node->right);
			ans += ")";
		}
	}

public:
	string tree2str(TreeNode* root) {
		ans += to_string(root->val);
		dfs(root);
		return ans;
	}
};

int main() {

}