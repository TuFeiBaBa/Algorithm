#include <string>

using namespace std;
/*
* Excel�������� https://leetcode.cn/problems/excel-sheet-column-title/description/
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            //��ʮ���ơ�16����������һ�������û��0
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