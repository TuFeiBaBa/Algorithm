#include <string>

using namespace std;
/*
* �ַ������ https://leetcode.cn/problems/add-strings/description/
* ���� ��������� https://leetcode.cn/problems/add-binary/description/
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int k = 0;
        //�����ȷ�ת�����ܵ�λ�͵�λ����
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            int m = i >= num1.size() ? 0 : num1[i] - '0';
            int n = i >= num2.size() ? 0 : num2[i] - '0';
            //��ǰλ��ֵ
            ans += (k + m + n) % 10 + '0';
            //�Ƿ񳬹�10������k��Ϊ1
            k = (k + m + n) / 10;
        }
        //���ܴ����������ֳ�����ȣ�����λ��Ӵ��ڵ���10�������"89"��"11"
        //ֱ�� ans += '1'Ҳû����
        if (k > 0) ans += k + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

}