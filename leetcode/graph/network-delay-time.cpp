#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

/**
* �����ӳ�ʱ��:https://leetcode.cn/problems/network-delay-time/
*
*
* �������壺
*	1.a->c��һ������̵�·��������a->b->c�����·����
*	2.ͼû��˵�������޻��ģ����ң�����ǹ̶��ģ�����㲻��֤�����Ϊ0���������������ǲ����õġ�
*	3.1 <= k <= n <= 100��1 <= times.length <= 6000�����������100�������Ǳ�ȴ���ܸߴ�6000�������ԣ�������Ǹ�����ͼ�����淴ӳ�˺ܿ������л��ģ�
*	4."��Ҫ��ò���ʹ���нڵ㶼�յ��źţ�"�źŷ��͵Ĺ��̲���DFS�ģ�����BFS���ǿɷ��ѵģ����зֲ�·ʱ���źŻ���ѣ�����˵���ƣ����Ա���ͬ·�����͡�
*	5."��Ҫ��ò���ʹ���нڵ㶼�յ��źţ�"Ҳ������һ��Ҫ�������·��
*
* Ϊʲô������������
*	1.����������Ҫ���ڼ�⻷�������ⲻ��֤�޻����л�������£�����Ҳ��ͨ�ģ���ͼ����ͨ�ģ���Ȼ�ܱ������ж���
*	2.�����������Ⱦ�Ҫ������Ϊ0������������л������ϵĵ������Ϊ��㡣
*	3.�������е������·����(longest-increasing-path-in-a-matrix.cpp)���������������ҵ������·������������ʵ���������������޻���ͼ���ҵ�·�����ͼ��
*	4.���γ̱� II��(course-schedule-ii.cpp)�����͵���������Ӧ��
*
* Dijkstra�㷨��
*	����˼�룺��δȷ���ڵ㡹�͡���ȷ���ڵ㡹
*		1.�����нڵ�ֳ����ࣺ��ȷ������㵽��ǰ������·���ȵĽڵ㣬�Լ�δȷ������㵽��ǰ������·���ȵĽڵ㡣
*		2.ÿ�δӡ�δȷ���ڵ㡹��ȡһ������������̵ĵ㣬��������Ϊ����ȷ���ڵ㡹�������������¡�����㵽�������С�δȷ���ڵ㡹�ľ��롣
*		  ֱ�����е㶼������Ϊ����ȷ���ڵ㡹��
*		3.�ýڵ� A�����¡��ڵ� B ����˼�ǣ�����㵽�ڵ� A �����·���ȼ��ϴӽڵ� A ���ڵ� B �ıߵĳ��ȣ�ȥ�Ƚ���㵽�ڵ� B �����·����
*		������dict����Ҫ��ʼ��ΪInt.Max��������0�������ǰ��С�ں��ߣ�����ǰ�߸��º��ߡ����ֲ���Ҳ���������ɳڡ���
*		�����ﰵ������Ϣ�ǣ�ÿ��ѡ��δȷ���ڵ㡹ʱ����㵽�������·���ĳ��ȿ��Ա�ȷ����
*	�Ż�˼�룺�۲�ö�ٷ���
*		1.ѡ��һ���µġ���ȷ���ڵ㡹ʱ��ֻ��ͨ�������Ƚ�ÿ��δȷ���ڵ�������dist��С����ѡ����С��һ��������ʱ�临�Ӷ���O(n)�����ԣ����Բ��á����ȶ��С��Ż���O(logn)
*		2.��ͼ��ʽ�������ڽӾ��󡣴���ʾ�������������ͼ������ǳ���ͼ����������ѡ���ڽӾ��󡿡�
*			1.�ڽӾ��󣺽ڵ���ΪV����ʹ��һ��V^2�ľ������洢�����֮������ӹ�ϵ���ʺϵ��������ӽ����������ƽ������ ��V^2��E�� ʱ�����ʺϡ�����ͼ����
*			2.�ڽӱ���һ���Զ���Ϊ�������б����飬���е�ÿ��Ԫ�ض��Ǻ͸ö������ڵĶ����б��ʺϵ��������ӽ������������ ��V��E�� ʱ�����ʺϡ�ϡ��ͼ����
*			3.�ߵ����飺��һ�����ʾ�ߡ�Ȼ�������飬�����еı߶���洢������ֻ�е�������Ҫȷ��ĳ���������Ӷ��ϸ�Ϊ ��O(E)�� ʱ���Żῼ��ʹ�á�
*		   �ᵽ���ִ�ͼ��ʽ�Ľⷨ��https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/
*	ʱ�临�Ӷȣ�https://blog.csdn.net/michealoven/article/details/114040136
*/
class Solution {
public:
	//����д����ö�ٷ�
	//ʱ�临�Ӷȣ�O(n^2+ m)������ m ������ times �ĳ��ȡ�
	//�ռ临�Ӷȣ�O(n^2)���ڽӾ�����ռ�� O(n^2)�Ŀռ䡣
	//int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	//	const int inf = INT_MAX / 2;
	//	vector<vector<int>> g(n, vector<int>(n, inf));
	//	for (auto& t : times) {
	//		int x = t[0] - 1, y = t[1] - 1;
	//		g[x][y] = t[2];
	//	}

	//	vector<int> dist(n, inf);
	//	dist[k - 1] = 0;
	//	vector<int> used(n);
	//	for (int i = 0; i < n; ++i) {
	//		int x = -1;
	//		for (int y = 0; y < n; ++y) {
	//			if (!used[y] && (x == -1 || dist[y] < dist[x])) {
	//				x = y;
	//			}
	//		}
	//		used[x] = true;
	//		for (int y = 0; y < n; ++y) {
	//			dist[y] = min(dist[y], dist[x] + g[x][y]);
	//		}
	//	}
	//	//max_element��������ѯ���ֵ���ڵĵ�һ��λ�á�������Ҫ*�������ã���ȡ���ֵ��
	//	int ans = *max_element(dist.begin(), dist.end());
	//	return ans == inf ? -1 : ans;
	//}

	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		//Ҳ�൱��Ԥ����ռ��˰ɣ�
		//vector<vector<int>> graph(n + 1, vector<pair<int, int>>(n + 1));
		vector<vector<pair<int, int>>> graph(n + 1);
		//Ԥ����ռ䣬��������
		for (auto& adj : graph) {
			adj.reserve(n + 1);
		}
		for (int i = 0; i < times.size(); i++) {
			graph[times[i][0]].emplace_back(times[i][1], times[i][2]);
		}
		//���϶����ᳬ��10001
		vector<int> dict(n + 1, 10001);
		//����ʼ��Ϊ0
		dict[k] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
		q.emplace(0, k);
		int ans = 0;
		while (!q.empty()) {
			pair<int, int> p = q.top();
			int time = p.first;
			int x = p.second;
			q.pop();
			//���ɱ�������ظ�������⣨����˵�����ʧЧ�����ڣ�
			if (time > dict[x]) continue;
			ans = max(ans, time);
			for (auto& e : graph[x]) {
				int y = e.first;
				int d = dict[x] + e.second;
				if (dict[y] > d) {
					dict[y] = d;
					q.emplace(d, y);
				}
			}
		}

		return count(dict.begin() + 1, dict.end(), 10001) > 0 ? -1 : ans;
	}
};

int main() {
	Solution su;
	vector<vector<int>> times{ {2, 1, 1},{2, 3, 1},{3, 4, 1} };
	int ans = su.networkDelayTime(times, 4, 2);
	cout << ans << endl;
}