#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
/*
* ��ͨ��Ŧ  https://leetcode.cn/problems/D9PW8w/description/
* Ӧ�ù�Ϊ���⡣��ĿҲ���Ͻ����������ظ��ߡ�
*/
class Solution {
//private: unordered_map<int, int> record;
public:
    int transportationHub(vector<vector<int>>& path) {
        //����ͳ�Ƴ��ߡ���ߵ���Ŀ
        unordered_map<int, int> record;
        for (auto& e : path) {
            //C++��map��Ĭ�ϻ��ʼ��intΪ0���Ӳ����������ƺ���map��λ���޹�(��Ա�������ֲ�����)��
            //������--
            record[e[0]]--;
            //�����++
            record[e[1]]++;
        }
        for (auto [key,num] : record) {
            if (num == record.size() - 1) {
                return key;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> path = { {0, 1},{0, 3},{1, 3},{2, 0},{2, 3} };
    Solution su;
    int ans = su.transportationHub(path);
    cout << ans << endl;
}