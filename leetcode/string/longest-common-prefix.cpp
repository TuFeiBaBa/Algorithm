#include <string>
#include <vector>

using namespace std;
/*
* �����ǰ׺��https://leetcode.cn/problems/longest-common-prefix/
*
* ����˼·�����жԱȼ��ɣ�һ�����ڲ�һ�£�ǰ��Աȳɹ����о��������ǰ׺
*
* ʱ�临�Ӷȣ�O(mn)��m���ַ���������n�ǹ���ǰ׺�ĳ��ȡ������£��������ַ�������ȡ�
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string ans;
        //����int len��min��������
        size_t len = INT_MAX;
        //���Բ����������õ�һ����size�������ȽϹ����У����ֳ�����ĳ���ַ����ĳ��ȣ�ֱ��return���
        for (auto& s : strs) {
            len = min(len, s.size());
        }
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) return ans;
            }
            //��ƴ�Ӹ���һ�㣬ֱ�Ӽ�¼���ȣ�������и����Ӧ��ǰ׺��
            ans += c;
        }
        return ans;
    }
};

int main() {

}