#include <vector>
#include <queue>

using namespace std;
/*
* �ҵ�����������ڵ�����Ľڵ� https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/
* 
* ����floyd��������û���⵽O(n^3)��ʱ�临�Ӷȿ϶��ᳬ��
* ��ʵֻ��Ҫ�������ڵ�ֱ����һ��dijkstra�㷨���ɣ��������ֻ��һ�����ߣ�����Ҫ�ٽ�ͼ��ʵ����Ҳ����Ҫ���ȶ��У���ͨ���м��ɣ�
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