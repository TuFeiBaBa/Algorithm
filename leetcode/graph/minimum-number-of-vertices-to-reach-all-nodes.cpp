#include <vector>
#include <set>
using namespace std;
/**
* ���Ե������е�����ٵ���Ŀ https://leetcode.cn/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
* 
* ����е��ᣬ�������·������Դ���·������С�����������𰸷�����ֻ��Ҫ������Ϊ0�ĵ㡣��
*/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        set<int> nodes;
        for (int i = 0; i < edges.size(); i++) {
            nodes.emplace(edges[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (nodes.find(i) == nodes.end()) ans.push_back(i);
        }
        return ans;
    }
};

int main() {

}