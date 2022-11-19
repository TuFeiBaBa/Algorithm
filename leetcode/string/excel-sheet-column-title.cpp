#include <string>

using namespace std;
/*
* Excel表列名称 https://leetcode.cn/problems/excel-sheet-column-title/description/
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            //和十进制、16进制这种有一点点区别，没有0
            --columnNumber;
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

}