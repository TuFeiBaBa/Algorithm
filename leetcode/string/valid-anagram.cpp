#include <vector>
#include <string>

using namespace std;
/*
* 有效的字母异位词 https://leetcode.cn/problems/valid-anagram/
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> r(26);
        for (int i = 0; i < s.size(); i++) {
            r[s[i] - 'a']++;
            r[t[i] - 'a']--;
        }
        for (int n : r) {
            if (n != 0) return false;
        }
        return true;
    }
};

int main() {

}