#include <string>
#include <unordered_map>

using namespace std;
/*
* Í¬¹¹×Ö·û´® https://leetcode.cn/problems/isomorphic-strings/description/
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> r;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            char d = t[i];
            if (m.find(c) == m.end() && r.find(d) == r.end()) {
                m[c] = d;
                r[d] = c;
            }
            else if (m[c] != d || r[d] != c) {
                return false;
            }
        }
        return true;
    }
};

int main() {

}