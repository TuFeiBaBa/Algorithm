#include <vector>
#include <queue>
using namespace std;
/**
* �ҵ����յİ�ȫ״̬��https://leetcode.cn/problems/find-eventual-safe-states/
*
* ����˼·��
* ��һ���ڵ�û�г��ߣ���ýڵ��ǰ�ȫ�ģ���һ���ڵ���������ĵ㶼�ǰ�ȫ�ģ���ýڵ�Ҳ�ǰ�ȫ�ġ�
* ������һ���ʣ����ǿ��Խ�ͼ�����б߷��򣬵õ�һ����ͼ��Ȼ���ڷ�ͼ��������������
*
*/
class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> g(n);
		vector<int> in(n);
		for (int i = 0; i < n; i++) {
			for (int j : graph[i]) {
				g[j].push_back(i);
				in[i]++;
			}
		}
		queue<int> q;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				q.push(i);
				ans.push_back(i);
			}
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : g[x]) {
				in[y]--;
				if (in[y] == 0) {
					q.push(y);
					ans.push_back(y);
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};


int main() {

}