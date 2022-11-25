#include <string>

using namespace std;
/*
* ·´×ª×Ö·û´® II https://leetcode.cn/problems/reverse-string-ii/description/
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        for (size_t i = 0; i < s.size(); i += 2 * k) {
            /*int m = i;
            int n = i + k - 1 < s.size() ? i + k - 1 : s.size() - 1;
            while (m < n) {
                swap(s[m], s[n]);
                m++;
                n--;
            }*/
            reverse(s.begin() + i, s.begin() + min(i + k, s.size()));
        }
        return s;
    }
};

int main() {

}