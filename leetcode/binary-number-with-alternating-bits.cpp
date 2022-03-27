
/**
* 方法一：模拟
* 方法二：位运算：先n右移一位，然后与n异或，如果满足要求，那么结果应该是111111...这时候，结果与（n+1）进行&，必然为0。(注意，把数值转为long，避免n + 1越界)
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