#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
/*
* 交通枢纽  https://leetcode.cn/problems/D9PW8w/description/
* 应该归为简单题。题目也不严谨，不能有重复边。
*/
class Solution {
//private: unordered_map<int, int> record;
public:
    int transportationHub(vector<vector<int>>& path) {
        //用来统计出边、入边的数目
        unordered_map<int, int> record;
        for (auto& e : path) {
            //C++的map，默认会初始化int为0？从测试来看，似乎与map的位置无关(成员变量、局部变量)。
            //出边则--
            record[e[0]]--;
            //入边则++
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