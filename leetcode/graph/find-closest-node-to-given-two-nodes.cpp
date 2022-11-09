#include <vector>
#include <queue>

using namespace std;
/*
* 找到离给定两个节点最近的节点 https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/
* 
* 想用floyd来做，但没留意到O(n^3)的时间复杂度肯定会超。
* 其实只需要对两个节点分别进行一次dijkstra算法即可（由于最多只有一条出边，不需要再建图，实际上也不需要优先队列，普通队列即可）
*/
class Solution {
	int inf = 100005;
public:
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		int n = edges.size();
		vector<int>dist1(n, inf), dist2(n, inf);
		queue<int>q;
		dist1[node1] = dist2[node2] = 0;
		q.push(node1);
		while (q.size()) {
			int u = q.front(); q.pop();
			int v = edges[u];
			if (v == -1 || dist1[v] < dist1[u] + 1)continue;
			dist1[v] = dist1[u] + 1;
			q.push(v);
		}
		q.push(node2);
		while (q.size()) {
			int u = q.front(); q.pop();
			int v = edges[u];
			if (v == -1 || dist2[v] < dist2[u] + 1)continue;
			dist2[v] = dist2[u] + 1;
			q.push(v);
		}
		int d = inf, ans = -1;
		for (int i = 0; i < n; ++i) {
			if (dist1[i] == inf || dist2[i] == inf)continue;
			if (d > (max(dist1[i], dist2[i]))) {
				d = max(dist1[i], dist2[i]);
				ans = i;
			}
		}
		return ans;
	}
};

int main() {

}