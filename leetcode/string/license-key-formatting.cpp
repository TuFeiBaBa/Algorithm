#include <string>

using namespace std;
/*
* 密钥格式化 https://leetcode.cn/problems/license-key-formatting/description/
*/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int m = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            char& c = s[i];
            if (isalnum(c)) {
                // if(isdigit(c)){
                //     ans += c;
                // }else{
                ans += toupper(c);
                // }
                //无法处理：--a-a-a-a--
                // if(m % k == 0 && i != 0){
                if (m % k == 0) {
                    ans += '-';
                }
                m++;
            }
        }
        //还有这种情况:"---",所以要判断ans.size() > 0
        if (ans.size() > 0 && ans[ans.size() - 1] == '-') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

}