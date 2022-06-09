#include <vector>
#include <queue>
using namespace std;
/**
* ���ڽ�ֲ��:https://leetcode.cn/problems/flower-planting-with-no-adjacent/
*
* ˼·��
*   1.˫��·����������ͼ
*   2.��ôȾɫ���о�û��ʲô�ر�õİ취��ֻ��BFS����DFS���ڱ����ߵĹ����У�
*     �����visited���ڱ�ʹ�������ֻ�����ʣ�µĻ��ּ��ɡ�
*     (...�����ǡ����л�԰�����3��·�����Խ�������뿪��ֻҪ����ڱ߼��ɡ�)
*
* ���壺���еĻ�԰��һ����һ����ͨ�����������Ƕ����ͨ��������Ҫ������п��ܵ���㡣
*
* ������д������ࣺhttps://leetcode.cn/problems/flower-planting-with-no-adjacent/solution/cyan-se-biao-ji-by-liu-xiang-3-pivx/
* (ֱ�ӱ������еĶ���ıߣ�ֻҪ�ڱ��������У�����ڱ��Ѿ�ʹ�õ���ɫ���������һ��δʹ����ɫ���ɡ�(����Ҫ��һ��"���"��ʼ������
*  ��ͨ���������������ͨ����������һ���߼��ɡ���������BFS�Ľⷨ�����˲���Ҫ�ļ����������))
*/
class Solution {
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<int> color(n);
		vector<vector<int>> graph(n + 1);
		for (int i = 0; i < paths.size(); i++) {
			graph[paths[i][0]].push_back(paths[i][1]);
			graph[paths[i][1]].push_back(paths[i][0]);
		}
		//ѭ������Ϊ���еĻ�԰��һ����һ����ͨ�����������Ƕ����ͨ����
		//����Ҫ������п��ܵ���㡣
		for (int i = 1; i <= n; i++) {
			if (color[i - 1] > 0) continue;
			queue<int> q;
			q.push(i);
			color[i - 1] = 1;
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int next : graph[node]) {
					if (color[next - 1] > 0) continue;
					vector<bool> visited(4);
					for (int n : graph[next]) {
						if (color[n - 1] > 0) visited[color[n - 1] - 1] = true;
					}
					for (int i = 0; i < visited.size(); i++) {
						if (!visited[i]) {
							color[next - 1] = i + 1;
							q.push(next);
							break;
						}
					}
				}
			}
		}
		return color;
	}
};

int main() {

}