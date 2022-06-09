#include <vector>

using namespace std;
/*
* 颜色交替的最短路径：https://leetcode.cn/problems/shortest-path-with-alternating-colors/
*
* 误区：求单元最短路径，最先联想到了dijkstra算法。但题目其实隐含了一个条件：每条边的长度都是一样的。
*		所以其实不需要dijkstra，普通的BFS即可，还要再加上红蓝颜色判断。
*
* 题解：https://leetcode.cn/problems/shortest-path-with-alternating-colors/solution/by-bai-mu-ying-li-dra-eniac-jehj/
*
* 核心思路：BFS + 二维visited去重。(不用二维visited应该也是可以的。根据起始边分别为红、蓝两种情况，进行两次BFS即可。)
*/
class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

	}
};


int main() {

}