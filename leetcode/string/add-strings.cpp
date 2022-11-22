#include <string>

using namespace std;
/*
* 字符串相加 https://leetcode.cn/problems/add-strings/description/
* 类似 二进制求和 https://leetcode.cn/problems/add-binary/description/
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int k = 0;
        //必须先反转，才能低位和低位对齐
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            int m = i >= num1.size() ? 0 : num1[i] - '0';
            int n = i >= num2.size() ? 0 : num2[i] - '0';
            //当前位的值
            ans += (k + m + n) % 10 + '0';
            //是否超过10，超过k则为1
            k = (k + m + n) / 10;
        }
        //可能存在两个数字长度相等，最后高位相加大于等于10的情况："89"、"11"
        //直接 ans += '1'也没问题
        if (k > 0) ans += k + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

}