#include <string>
#include <vector>

using namespace std;
/*
* �ж������� https://leetcode.cn/problems/is-subsequence/description/
* ��⣺https://leetcode.cn/problems/is-subsequence/solutions/346539/pan-duan-zi-xu-lie-by-leetcode-solution/
* 
* �����ǽ��װ�Ľⷨ
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > f(m + 1, vector<int>(26, -1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a')
                    f[i][j] = i;
                else
                    f[i][j] = f[i + 1][j];
            }
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            index = f[index][s[i] - 'a'];
            if (index == -1) return false;
            //����index++����Ȼs = "aaaaaa" t = "bbaaaa"��f[i][s[i] - 'a']һֱ��2������ж�Ϊtrue
            //�������index++����Ҫ���ⷨ�� https://leetcode.cn/problems/is-subsequence/solutions/82137/dui-hou-xu-tiao-zhan-de-yi-xie-si-kao-ru-he-kuai-s/
            //Ҫ����f�Ķ��壬f[i][j]Ҫ��ʼ��Ϊ0��Ȼ��f[i][j]�������һ��
            index++;
        }
        return true;
    }
};

int main() {

}