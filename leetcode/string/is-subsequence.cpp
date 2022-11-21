#include <string>
#include <vector>

using namespace std;
/*
* 判断子序列 https://leetcode.cn/problems/is-subsequence/description/
* 题解：https://leetcode.cn/problems/is-subsequence/solutions/346539/pan-duan-zi-xu-lie-by-leetcode-solution/
* 
* 下面是进阶版的解法
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > f(m + 1, vector<int>(26, -1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a')
                    f[i][j] = i;
                else
                    f[i][j] = f[i + 1][j];
            }
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            index = f[index][s[i] - 'a'];
            if (index == -1) return false;
            //必须index++。不然s = "aaaaaa" t = "bbaaaa"，f[i][s[i] - 'a']一直是2，结果判定为true
            //如果不想index++，那要按解法： https://leetcode.cn/problems/is-subsequence/solutions/82137/dui-hou-xu-tiao-zhan-de-yi-xie-si-kao-ru-he-kuai-s/
            //要更改f的定义，f[i][j]要初始化为0，然后f[i][j]存的是下一步
            index++;
        }
        return true;
    }
};

int main() {

}