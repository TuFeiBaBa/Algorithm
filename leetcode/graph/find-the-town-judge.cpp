#include <vector>
using namespace std;
/*
* ����˼·��ֻͳ�Ƴ���
* 
* �޷�����n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
* 
* ��1 <= n <= 1000��0 <= trust.lenght <= 10^4���Կ������߿�����Զ���ڵ�ġ����ԣ�
* ����"ÿ���ˣ������٣������η���" ������ָÿ����ֻ�����η��١�
* 
* ��ʵ����3��"ֻ��һ����ͬʱ�������� 1 ������ 2 "�Ƕ���ġ�ֻҪû���ظ��ߣ���������1��2���϶���������3��
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
* �ҵ�С��ķ���:https://leetcode.cn/problems/find-the-town-judge/
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
            //ֱ��return���ɡ�ֻ������һ����ͬʱ�����������
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