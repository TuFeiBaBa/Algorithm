#include <vector>
#include <string>

using namespace std;
/*
* 最长回文串 https://leetcode.cn/problems/longest-palindrome/description/
*/
class Solution {
public:
    int longestPalindrome(string s) {
        //cout << 'a' - 'A' << endl;
        //直接用128也是可以的
        vector<int> r(58);
        for (auto& c : s) {
            r[c - 'A']++;
        }
        int ans = 0;
        for (auto& n : r) {
            //有问题，无法正确处理"ccc"
            //if (n % 2 == 0) ans += n;

            //字符出现的次数最多用偶数次。
            //if (n > 0) ans += n / 2 * 2;
            ans += n - (n & 1);
        }
        return ans >= s.size() ? ans : ans + 1;
    }
};

int main() {

}