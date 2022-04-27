#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 1.有多条路径时，如何选择?
 *	1.选择字母序最小的一条。不可行：可能走进死胡同，字母序最小的可能要最后才能走
 * 2.采用DFS、BFS：
 *	1.BFS：怎么保存路径？parent似乎不行，可能会被覆盖
 * 3.拓扑排序呢？
 *	1.不行。示例2就是一个例子，没有入度为0的点
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
		//类似Java的ArrayList，每次都在头进行insert，每次都会发生拷贝
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