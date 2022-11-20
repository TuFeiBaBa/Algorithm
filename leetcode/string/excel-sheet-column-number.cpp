#include <string>

using namespace std;
/*
* Excel ±íÁĞĞòºÅ https://leetcode.cn/problems/excel-sheet-column-number/description/
*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long k = 1;
        int ans = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            char c = columnTitle[i];
            ans += (c - 'A' + 1) * k;
            k *= 26;
        }
        return ans;
    }
};

int main() {

}