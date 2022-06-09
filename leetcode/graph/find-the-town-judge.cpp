#include <vector>
using namespace std;
/*
* 错误思路：只统计出边
* 
* 无法处理：n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
* 
* 从1 <= n <= 1000，0 <= trust.lenght <= 10^4可以看出，边可能是远多于点的。所以，
* 满足"每个人（除法官）都信任法官" ，不是指每个人只能信任法官。
* 
* 其实条件3："只有一个人同时满足属性 1 和属性 2 "是多余的。只要没有重复边，满足条件1、2，肯定满足条件3。
*/
//class Solution {
//public:
//    int findJudge(int n, vector<vector<int>>& trust) {
//        if (trust.empty() && n > 1) return -1;
//        if (trust.empty() && n == 1) return 1;
//        vector<int> record(n + 1);
//        int parent = trust[0][1];
//        for (int i = 0; i < trust.size(); i++) {
//            if (trust[i][1] != parent) return -1;
//            record[trust[i][0]]++;
//        }
//        int cnt = 0;
//        int ans = -1;
//        for (int i = 1; i <= n; i++) {
//            if (record[i] == 0) {
//                cnt++;
//                ans = i;
//            }
//        }
//        return cnt == 1 ? ans : -1;
//    }
//};

/**
* 找到小镇的法官:https://leetcode.cn/problems/find-the-town-judge/
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n > 1) return -1;
        if (trust.empty() && n == 1) return 1;
        vector<int> in(n + 1);
        vector<int> out(n + 1);
        for (int i = 0; i < trust.size(); i++) {
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        int cnt = 0;
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            //直接return即可。只可能有一个点同时满足这个条件
            if (out[i] == 0 && in[i] == n - 1) {
                cnt++;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};

int main() {

}