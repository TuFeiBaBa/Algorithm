#include <string>

using namespace std;
/*
* ��������� https://leetcode.cn/problems/add-binary/description/
* 
* ����㣺
*   1.Ӧ�ô����ַ�����ĩβ��ʼ�Ƚ�
*   2.���ַ������Ȳ�һ����ͬ
*   3.���ַ������������λ����1
*/
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        string ans;
//        int k = 0;
//        string& m = a.size() >= b.size() ? a : b;
//        string& n = a.size() >= b.size() ? b : a;
//        for (int i = m.size() - 1, j = n.size() - 1; i >= 0 && j >= 0; i--, j--) {
//            if (m[i] == '1' && n[j] == '1') {
//                if (k > 0) {
//                    ans += '1';
//                }
//                else {
//                    ans += '0';
//                    k = 1;
//                }
//            }
//            else if (m[i] == '1' || n[j] == '1') {
//                if (k > 0) {
//                    ans += '0';
//                }
//                else {
//                    ans += '1';
//                    k = 0;
//                }
//            }
//            else {
//                ans += to_string(k);
//                k = 0;
//            }
//        }
//        for (int i = m.size() - n.size() - 1; i >= 0; i--) {
//            if (m[i] == '1') {
//                if (k > 0) {
//                    ans += '0';
//                }
//                else {
//                    ans += '1';
//                    k = 0;
//                }
//            }
//            else {
//                ans += to_string(k);
//                k = 0;
//            }
//        }
//        if (k > 0) ans += to_string(k);
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

}