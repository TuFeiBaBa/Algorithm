#include <vector>
#include <string>

using namespace std;
/*
* ����Ĵ� https://leetcode.cn/problems/longest-palindrome/description/
*/
class Solution {
public:
    int longestPalindrome(string s) {
        //cout << 'a' - 'A' << endl;
        //ֱ����128Ҳ�ǿ��Ե�
        vector<int> r(58);
        for (auto& c : s) {
            r[c - 'A']++;
        }
        int ans = 0;
        for (auto& n : r) {
            //�����⣬�޷���ȷ����"ccc"
            //if (n % 2 == 0) ans += n;

            //�ַ����ֵĴ��������ż���Ρ�
            //if (n > 0) ans += n / 2 * 2;
            ans += n - (n & 1);
        }
        return ans >= s.size() ? ans : ans + 1;
    }
};

int main() {

}