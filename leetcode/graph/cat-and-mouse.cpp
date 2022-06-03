#include <vector>
using namespace std;

/*
* 猫和老鼠:https://leetcode.cn/problems/cat-and-mouse/
* 
* 个人思路：
* 无环：看谁离节点0近？
*       猫近，那是否和老鼠在通往节点0时，有重叠的路径（猫要提前拦截老鼠）？没有，则无法拦截老鼠。
*       老鼠近，老鼠赢
* 有环：看谁离节点0近？
*       猫近。关键在于判断平局的条件。
*             有环且勾成环的边数大于3，则平局
*             否则猫胜
*       老鼠近，老鼠赢
*/
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {


    }
};

int main() {

}