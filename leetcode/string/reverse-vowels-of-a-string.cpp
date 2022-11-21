#include <string>
#include <unordered_set>

using namespace std;
/*
* 反转字符串中的元音字母 https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
*/
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> set = { 'a','e','i','o','u','A','E','I','O','U' };
        while (i < j) {
            if (set.find(s[i]) == set.end()) {
                i++;
                continue;
            }
            if (set.find(s[j]) == set.end()) {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

int main() {

}