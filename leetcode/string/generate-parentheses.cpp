#include <vector>
#include <string>

using namespace std;
/*
* 括号生成 https://leetcode.cn/problems/generate-parentheses/description/
*/
class Solution {
private:
    vector<string> ans;
    string s;

    void dfs(int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(s);
        }
        if (l > 0) {
            s.push_back('(');
            dfs(l - 1, r);
            s.pop_back();
        }
        //会有这样的情况"(()))("
        //if(r > 0) {
        if (l < r && r > 0) {
            s.push_back(')');
            dfs(l, r - 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ans;
    }
};

int main() {

}