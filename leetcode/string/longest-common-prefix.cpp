#include <string>
#include <vector>

using namespace std;
/*
* 最长公共前缀：https://leetcode.cn/problems/longest-common-prefix/
*
* 核心思路：逐列对比即可，一旦存在不一致，前面对比成功的列就是最长公共前缀
*
* 时间复杂度：O(mn)。m是字符串数量，n是公共前缀的长度。最坏情况下，是所有字符串都相等。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string ans;
        //换成int len，min方法报错
        size_t len = INT_MAX;
        //可以不遍历，先拿第一个的size，遍历比较过程中，发现超出了某个字符串的长度，直接return结果
        for (auto& s : strs) {
            len = min(len, s.size());
        }
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) return ans;
            }
            //不拼接更好一点，直接记录长度，最后再切割出对应的前缀？
            ans += c;
        }
        return ans;
    }
};

int main() {

}