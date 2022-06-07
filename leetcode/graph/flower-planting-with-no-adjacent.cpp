#include <vector>
using namespace std;
/**
* 不邻接植花:https://leetcode.cn/problems/flower-planting-with-no-adjacent/
*
* 思路：
*   1.双向路径，即无向图
*   2.怎么染色？感觉没有什么特别好的办法。只能BFS或者DFS，在遍历边的过程中，
*     检查已visited的邻边使用了哪种花，挑剩下的花种即可。
*     (...还真是。所有花园最多有3条路径可以进入或者离开，只要检查邻边即可。)
*/
class Solution {
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

	}
};

int main() {

}