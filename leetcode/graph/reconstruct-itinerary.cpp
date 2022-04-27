#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 1.�ж���·��ʱ�����ѡ��?
 *	1.ѡ����ĸ����С��һ���������У������߽�����ͬ����ĸ����С�Ŀ���Ҫ��������
 * 2.����DFS��BFS��
 *	1.BFS����ô����·����parent�ƺ����У����ܻᱻ����
 * 3.���������أ�
 *	1.���С�ʾ��2����һ�����ӣ�û�����Ϊ0�ĵ�
 */
class Solution {
private:
	void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<>>>& map, string from, vector<string>& paths) {
		/*if (map.find(from) == map.end() || map[from].empty()) {
			paths.insert(paths.begin(), from);
			return;
		}*/
		while (map.find(from) != map.end() && !map[from].empty()) {
			string to = map[from].top();
			map[from].pop();
			dfs(map, to, paths);
		}
		//����Java��ArrayList��ÿ�ζ���ͷ����insert��ÿ�ζ��ᷢ������
		//paths.insert(paths.begin(), from);
		paths.emplace_back(from);
	}

public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<>>> map;
		vector<string> paths;
		for (auto& ticket : tickets) {
			map[ticket[0]].emplace(ticket[1]);
		}
		dfs(map, "JFK", paths);
		reverse(paths.begin(), paths.end());
		return paths;
	}
};

int main() {

}