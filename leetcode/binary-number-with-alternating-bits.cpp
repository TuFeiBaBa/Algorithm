
/**
* ����һ��ģ��
* ��������λ���㣺��n����һλ��Ȼ����n����������Ҫ����ô���Ӧ����111111...��ʱ�򣬽���루n+1������&����ȻΪ0��(ע�⣬����ֵתΪlong������n + 1Խ��)
* https://leetcode-cn.com/problems/binary-number-with-alternating-bits/solution/jiao-ti-wei-er-jin-zhi-shu-by-leetcode-s-bmxd/
**/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i = n;
        int last_mod = -1;
        while (i > 0) {
            int mod = i % 2;
            if (mod == last_mod) return false;
            last_mod = mod;
            i = i / 2;
        }
        return true;
    }
};

int main() {

}