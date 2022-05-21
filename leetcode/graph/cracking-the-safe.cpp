#include <string>
#include <unordered_set>
#include <iostream>

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
* Hierholzer算法：可以在一个欧拉图中找出欧拉回路。https://taodaling.github.io/blog/2019/04/25/Hierholzer%E7%AE%97%E6%B3%95/
*	void dfs(Node node, Deque trace){
*		while(!node.edges.isEmpty()){
*			Node next = node.edges.removeLast();
*			dfs(next, trace);
*		}
*		trace.addLast(node);
*	}
*
* 『图论』入门以及 Hierholzer 算法：https://zhuanlan.zhihu.com/p/108411618
*
*
* 题解：
* https://leetcode.cn/problems/cracking-the-safe/solution/po-jie-bao-xian-xiang-by-leetcode-solution/
* 贪心构造（详细解释了官解的答案，并提供了一种贪心思路与证明）：https://leetcode.cn/problems/cracking-the-safe/solution/yi-bu-yi-bu-tui-dao-chu-0ms-jie-fa-tan-xin-gou-zao/
* yiduobo的每日leetcode 753.破解保险箱：https://zhuanlan.zhihu.com/p/338167746
*/
//class Solution {
//private:
//	unordered_set<int> seen;
//	string ans;
//	int highest;
//	int k;
//
//public:
//	void dfs(int node) {
//		for (int x = 0; x < k; ++x) {
//			int nei = node * 10 + x;
//			if (!seen.count(nei)) {
//				seen.insert(nei);
//				//nei顶多是 n - 1 位数，所以 % highest，目的是为了去掉最高位
//				cout << "？" << x << endl;
//				dfs(nei % highest);
//				cout << "->" << x << endl;
//				//逆后序
//				//为什么是逆后序?
//				// 仔细观察前序和逆后序的结果：如图
//				
//				//与原版Hierholzer算法的一点差异是：原版保存的是节点，这里保存的是边
//				ans += (x + '0');
//			}
//		}
//	}
//
//	string crackSafe(int n, int k) {
//		//即10..00 (有n - 1个0)
//		highest = pow(10, n - 1);
//		this->k = k;
//		dfs(0);
//		ans += string(n - 1, '0');
//		return ans;
//	}
//};

class Solution {
public:
	string crackSafe(int n, int k) {
		//k的n - 1次方个节点，每个节点有k条出边，所以图有k的n次方条边。
		int edgesNum = pow(k, n), nodeNum = pow(k, n - 1);
		//数组node是用来存储每个节点的出边，出边用索引表示，最大索引是k - 1
		vector<int> node(nodeNum, k - 1);
		//这里多出来的n-1，其实是因为要初始化第一个节点"00..0"
		string s(edgesNum + (n - 1), '0');
		//idx表示节点索引
		for (int i = n - 1, idx = 0; i < s.size(); ++i) {
			int edge = node[idx];
			s[i] = edge + '0';
			//将对应的边出栈
			node[idx]--;
			//一共k ^ (n - 1)个节点，可以看作n - 2位的k进制数能表示的数，
			//即最小为0，最大为k ^ (n - 1) - 1 (想象一下10进制，比如10^2，就好理解了)。
			//如果当前节点对应的数为 a1a2⋯an−1，那么它的第 x 条出边就连向数 a2⋯an−1x 对应的节点
			//那么计算通向的下一个节点，需要先对当前的数进行左移操作（即在数值右端补0），
			//所以先 * k, 然后加上出边x，最后再通过 % 来抹去高位的a1。
			// 
			//官解的highest用的是10进制，由于k的取值范围是[1, 10]，所以是可行的。
			//如果你将官解的highest改成16进制，也是可行的。具体看下方提供的代码。
			//但是这里是否可以直接用10来取代k呢？不可行，如果换成了10，
			//k小于10的时候，其实是将原本紧密排列的节点索引idx零散地映射在了[0, 10^(n-1))上，
			//所以idx的取值是可能大于k ^ (n - 1) - 1，就会在node上发生数组越界。
			//如果要采用10进制，需要对数组进行扩容。具体参考下方提供的代码。
			idx = (idx * k + edge) % nodeNum;
		}
		return s;
	}
};

/**
* 采用16进制来修改官解的代码（不推荐，仅用于举例说明）
*/
//class Solution {
//private:
//	unordered_set<int> seen;
//	string ans;
//	int highest;
//	int k;
//
//public:
//	void dfs(int node) {
//		for (int x = 0; x < k; ++x) {
//			//改为16进制
//			int nei = node * 16 + x;
//			if (!seen.count(nei)) {
//				seen.insert(nei);
//				dfs(nei % highest);
//				ans += (x + '0');
//			}
//		}
//	}
//
//	string crackSafe(int n, int k) {
//		//改为16进制
//		highest = pow(16, n - 1);
//		this->k = k;
//		dfs(0);
//		ans += string(n - 1, '0');
//		return ans;
//	}
//};

/**
* 采用10进制来调整上面的代码（不推荐，仅用于举例说明，存在明显的空间浪费）
*/
//class Solution {
//public:
//	string crackSafe(int n, int k) {
//		int edgesNum = pow(k, n), nodeNum = pow(k, n - 1);
//		//采用10进制，node数组存在空间浪费
//		int highest = pow(10, n - 1);
//		vector<int> node(highest, k - 1);
//		string s(edgesNum + (n - 1), '0');
//		for (int i = n - 1, idx = 0; i < s.size(); ++i) {
//			int edge = node[idx];
//			s[i] = edge + '0';
//			node[idx]--;
//			//采用10进制
//			idx = (idx * 10 + edge) % highest;
//		}
//		return s;
//	}
//};

int main() {
	Solution su;
	su.crackSafe(3, 2);

	int  num = 0;
}