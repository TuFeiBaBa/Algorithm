#include <vector>
#include <set>
using namespace std;
/**
* 可以到达所有点的最少点数目 https://leetcode.cn/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
* 
* 想得有点歪，想了最短路径、多源最短路径、最小生成树，看答案发现是只需要检查入度为0的点。。
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