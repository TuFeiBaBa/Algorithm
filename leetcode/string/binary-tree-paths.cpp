#include <string>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//class Solution {
//private:
//	string s;
//	vector<string> ans;
//	void dfs(TreeNode* node) {
//		if (!node->left && !node->right) {
//			ans.push_back(s);
//			return;
//		}
//		s.push_back('-');
//		s.push_back('>');
//		if (node->left) {
//			//val的取值[-100,100]，val小于0，或者val大于等于10时，下面代码都会出问题
//			/*s.push_back(node->left->val + '0');
//			dfs(node->left);
//			s.pop_back();*/
//
//			string v = to_string(node->left->val);
//			s += v;
//			dfs(node->left);
//			s.erase(s.size() - v.size(), v.size());
//		}
//		if (node->right) {
//			/*s.push_back(node->right->val + '0');
//			dfs(node->right);
//			s.pop_back();*/
//
//			string v = to_string(node->right->val);
//			s += v;
//			dfs(node->right);
//			s.erase(s.size() - v.size(), v.size());
//		}
//		s.pop_back();
//		s.pop_back();
//	}
//
//public:
//	vector<string> binaryTreePaths(TreeNode* root) {
//		s.push_back(root->val);
//		dfs(root);
//		return ans;
//	}
//};

/*
* 二叉树的所有路径 https://leetcode.cn/problems/binary-tree-paths/description/
* 
* 上面的解法是自己写的常规的回溯
* 
* 下面的解法，参考自：https://leetcode.cn/problems/binary-tree-paths/solutions/1950537/zai-o-by-youthful-i2hodeszzz-5tnv/?languageTags=cpp&topicTags=backtracking
* 减少了s的字符弹栈，个人认为更优
*/
class Solution {
public:
    vector<string> res;

    void dfs(TreeNode* p, string& s) {
        s += to_string(p->val);
        if (!p->left && !p->right) {
            //c++ move函数到底是什么意思？
            //https://www.zhihu.com/question/64205844
            res.emplace_back(std::move(s));
            return;
        }
        s += "->";
        if (p->left && p->right) {
            auto str_copy = s;
            dfs(p->left, s);
            dfs(p->right, str_copy);
        }
        else if (p->left && !p->right) {
            dfs(p->left, s);
        }
        else {
            dfs(p->right, s);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string start;
        dfs(root, start);
        return res;
    }
};

int main() {

}