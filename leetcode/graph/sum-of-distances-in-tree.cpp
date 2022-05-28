#include <vector>
using namespace std;
/**
* ���о���֮�ͣ�https://leetcode.cn/problems/sum-of-distances-in-tree/
*
* �����Ƶ�˼·��
*	1.1 <= n <= 3 * 10^4�������⣬��ȡһ���ڵ�ľ���ͣ���Ҫ�Ըýڵ�Ϊ���ڵ㣬������������������������ʱ����n��
*	  ���ǻ�ȡ���нڵ�ľ��룬ʱ�临�Ӷȣ���������O(n^2)�ˡ�
*	2.��취�Ż�ʱ�临�Ӷȣ���û�а취�ȼ�����ĳ���ڵ�Ϊ���ڵ㣬�������͡�Ȼ���Դˣ���������������ľ���͡�
*	3.��һ�룬�ڱ���һ������ʱ�������ܻ��ʲô�����ĸ߶ȡ�ǰ�к���������ȡ�������������������С������˵�ڵ���Ŀ��
*	4.������û��ע�⵽����ʾ��һ���ⲻ�Ǹ�������������N������֪�����������ڵ���Ŀ���������ڵ㣬�ƶ�����ڵ�ʱ��
*	  ��ڵ�ľ���ͣ���ȻҪ���٣���ڵ�������ڵ���Ŀ - 1��(����������)�����ϣ��ҽڵ�������ڵ���Ŀ + 1��(����ԭ���ڵ�)
*
*	  ��ȷ˼·������dp[u]��ʾ��uΪ�������������������ӽڵ㵽���ľ���֮�ͣ�ͬʱ����sz[u]��ʾ��uΪ���������Ľڵ�������������u����
*	  ��			dp[u] = dp[v1] + sz[v1] + dp[v2] + sz[v2] + ...  (v1��v2��u��ֱ���ӽڵ�)
*					sz[u] = sz[v1] + sz[v2]
*     ���Ǳ������������Ե����ϣ����ɵõ�dp[root]
*	5.��ô����������һ��û�������ף�
*		1.edges��û�б�֤�ڵ�0���Ǹ��ڵ㣬Ҳǿ������������ġ������޷��Դ�ͳ�ķ�ʽ���򵥽�����ڵ㡢�ҽڵ�����������ṹ��
*		  ��edges��ͼ��ֻ�ܽ�������ͼ��
*	6.��ô������������ͼ������ȥ�޻ط���������Ƿ���parent���������������ֻ��һ���ߣ���ֻ����parent�ˣ�����ȷ���������ĸ�����
*	7.״̬ת�ƣ�ת�Ƹ��ڵ㣬u->v
*		v��Ϊu�ṩ�κι����ˣ�����			dp[u] = dp[u] - (dp[v] + sz[v])
*											sz[u] = sz[u] - sz[v]
*       uΪ�µĸ��ڵ�v�ṩ�˹��ף�����		dp[v] = dp[v] + (dp[u] + sz[u])
*											sz[v] = sz[v] + sz[u]
*/
class Solution {
private:
	vector<int> dp;
	vector<int> sz;
	vector<int> ans;
	void dfs(vector<vector<int>>& graph, int parent) {
		sz[parent] = 1;
		for (int e : graph[parent]) {
			if (sz[e] != 0) continue;
			dfs(graph, e);
			sz[parent] += sz[e];
			dp[parent] += dp[e] + sz[e];
		}
	}

	void dfs2(vector<vector<int>>& graph, int old, int n) {
		dp[old] = dp[old] - (dp[n] + sz[n]);
		sz[old] = sz[old] - sz[n];
		dp[n] = dp[n] + (dp[old] + sz[old]);
		sz[n] = sz[n] + sz[old];
		ans[n] = dp[n];
		for (int e : graph[n]) {
			if (e == old) continue;
			dfs2(graph, n, e);
		}
		//����
		//��д�������⣺Ӧ�ÿ��ǰ�ǰ��ľ�ֵ�������������ټ���
		dp[n] = dp[n] - (dp[old] + sz[old]);
		sz[n] = sz[n] - sz[old];
		dp[old] = dp[old] + (dp[n] + sz[n]);
		sz[old] = sz[old] + sz[n];
	}
public:
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n);
		dp = vector<int>(n);
		sz = vector<int>(n);
		ans = vector<int>(n);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		dfs(graph, 0);
		ans[0] = dp[0];
		//����д�ò��ã�ͳһ���ϵ�dfs2�������
		//�ο���https://leetcode.cn/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
		for (int e : graph[0]) {
			dfs2(graph, 0, e);
		}
		return ans;
	}
};

int main() {

}