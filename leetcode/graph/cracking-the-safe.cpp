#include <string>
#include <unordered_set>

using namespace std;

/**
* 破解密码箱：https://leetcode.cn/problems/cracking-the-safe/
* 中文题目少了部分内容，建议读英文版：https://leetcode.com/problems/cracking-the-safe/
* 题目的意思，其实是让你找到所有可能是密码串的字符串，然后"合并"它们成最短字符串。
*
* 思路：
*	1.看数据量：n ：[1,4],k：[1,10]。另外max(k^n)=4096（这个限制不关键，没有限制，max(k^n)也就10000）
*	2.获取每个可能的密码串：暴力解：时间复杂度是O(k^n)，针对数据量而言，是可行的
*		以k=10，n=4为例，暴力解的伪代码就是
*			void dfs(int num,int n,int k){
*				for(int i=0;i < k;i++){
*					//最多n层递归
*					dfs(...);
*				}
*			}
*	3.如何"合并"字符串？没有思路...
*
*
* Eulerian path：https://en.wikipedia.org/wiki/Eulerian_path
* 欧拉定理：当且仅当每个顶点的度数为偶数时，【连通图】才具有欧拉回路（或者说欧拉环）。
*		   1.如果是有向图，图是连通的，每个顶点的入度和出度都相同时，该图有欧拉回路。（如：每个顶点都有k条入边和出边时，2k必然是偶数，故该图有欧拉回路）
*		   2.如果是无向图，图是连通的，每个顶点的度数为偶数时，该图有欧拉回路。
*
* 半欧拉图：图是连通的，且仅有两个奇度点（与欧拉图的区别在于,欧拉图要求是闭路径,而半欧拉图不要求是闭路径）
*
* 图中的度：顶点的度(degree)，就是指和该顶点相关联的边数。在有向图中，度又分为入度和出度。
*
*
* 题解：https://leetcode.cn/problems/cracking-the-safe/solution/po-jie-bao-xian-xiang-by-leetcode-solution/
* 具体地，我们将所有的 n-1 位数作为节点，共有 k^(n-1)个节点，每个节点有 k 条入边和出边。如果当前节点对应的数为 a1a2..a(n-1)x，那么它的第
* x条出边就连向数a2...a(n-1)x 对应的节点。这样我们从一个节点顺着第 x 条边走到另一个节点，就相当于输入了数字 x。
*
* Hierholzer算法：可以在一个欧拉图中找出欧拉回路。https://blog.csdn.net/qq_19446965/article/details/104783782
*/
class Solution {
private:
	unordered_set<int> seen;
	string ans;
	int highest;
	int k;

public:
	void dfs(int node) {
		for (int x = 0; x < k; ++x) {
			int nei = node * 10 + x;
			if (!seen.count(nei)) {
				seen.insert(nei);
				//nei顶多是 n - 1 位数，所以 % highest，目的是为了去掉最高位
				dfs(nei % highest);
				ans += (x + '0');
			}
		}
	}

	string crackSafe(int n, int k) {
		//即10..00 (有n - 1个0)
		highest = pow(10, n - 1);
		this->k = k;
		dfs(0);
		ans += string(n - 1, '0');
		return ans;
	}
};

int main() {

}