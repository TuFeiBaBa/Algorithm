#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;
/*
* ���ﴫ�� https://leetcode.cn/problems/6UEx57/
* 
* ��һ������������ʼ��ĥBFS��û��˼·����������ʶ���������·����Dijkstra��ʱ�临�Ӷ�Ϊ���ؽⷨ��O((V + E��logV���϶�����AC��
* E�����������ᳬ��4V�����ѵ�������ô��ͼ��
*/
class Solution {
private:
	vector<vector<int>> move = { {1,0},{-1,0},{0,1},{0,-1} };
	vector<char> direct = { 'v','^','>','<' };
public:
	int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
		int n = matrix.size() * matrix[0].size();
		vector<vector<pair<int, int>>> g(n);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				//���ǲ�С��д��matrix.size()
				//int node = i * matrix.size() + j;
				int node = i * matrix[0].size() + j;
				for (int k = 0; k < move.size(); k++) {
					int x = i + move[k][0];
					int y = j + move[k][1];
					if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) continue;
					int node2 = x * matrix[0].size() + y;
					//int d = direct[k] == matrix[x][y] ? 0 : 1;
					int d = direct[k] == matrix[i][j] ? 0 : 1;
					g[node].emplace_back(node2, d);
				}
			}
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.emplace(0, start[0] * matrix[0].size() + start[1]);
		vector<int> dict(n, INT_MAX);
		dict[start[0] * matrix[0].size() + start[1]] = 0;
		while (!pq.empty()) {
			auto [d, from] = pq.top();
			pq.pop();
			if (d > dict[from]) continue;
			for (auto& [to, side] : g[from]) {
				int dt = d + side;
				if (dt < dict[to]) {
					dict[to] = dt;
					pq.emplace(dt, to);
				}
			}
		}
		return dict[end[0] * matrix[0].size() + end[1]];
	}
};

int main() {
	vector<string> matrix = {"<^>><^v>^<<><v><<>v>^v><vv<v>>>^<>vv>v>^v^^><vvv<>",">>v^vvv^<>>^v<<>^^<^^>v<<<<^<v^v<^^>v^<^v<<^<>v^^>",">>^><^^<>^vv<>vv<v^^<<<^<^<<^<^^^^><>><vv^<v>><^<>","><<>><^^^^v^>vv^^vv<>>>^<<><>^>v<v<<v^^vv<>^>v<^<<",">v>>^^vv<v<^><<^<^v<<^>vv<<<><>v^v<>vv>^v<>v^>^^<<","v><^<<v<vv><^<v>>^^^>>><<<^>>^><^^<vv<^^^>>^v^>^^<",">^v>><>^><<^^>^<vv<v>>>><v>^v>v<<<>>><^>v>>>>>^><^","<<v><v^vv>><vv^<><v><vv><>><>^v^vvv<^<^>>v^>v>vvvv","vv<>^><>^^v<v<^vv^<^><v<^><^<^<v<><<>^v>^<^^vvv<^^","<>^^<v^^^<^^v>>><>vv<>><v><v>^<^v>>^v^<>>^<>v^<^^>","^^v><vv>^^<>vv^<v><>>^<vv>^>>^v<^<>>>^^><^^v>^>^v^","v>^<v^<><><<^v<^<>>><v<<^vv>>><^^<v^>^^v<><<v^<^<<","v><v^vv^<>^<vv>^^><v<>^>v>v>>^v>v^<^v^>^^<<vv>><v^","v<>vv<>>>vv>>><>>v^>^><v<>v<^><^>^v<>>^<^v<^v>^v<<","^<^<^vvvv^<>^<^v<>v<^>>^^vvv>^v>v<^>vv><vv^v>^<<<<","<<v^^<<<>>>v^v^^<>^>>^>^<^^v><<vv>v^^v<v>v><^^^>^v","<v><^<>v>v^v^v^^v^<v>^>>^^^<><>>>vv<<v^<>^>^><^v^v","<<>^<<<>^>>vv^^><>^>><^^^><<v<v>v><>><<^v<>>v^<^vv","^v><^>>^<v<>v^^>^<>>^>><>^^>v^>>^^v^v>^v<v>^vv^<v<","v^^v>^<<<v>>^<<><>>>>><<<>^<^>>><^^>vv^>v^^v^><>>>","<>v>>vvv<>v^v<vv><^vvv^v^><>^^>^^<^^<v^vv>>><><><v","v>><<^>^<<^>^^>>v<<^<v^^><<v<v<<v^v<^<<<<<>vv><<^v","^^^v<<vv<<<^v^>><>>^vv^^^^><v^v<>><>^<v^^<v<v^^<^v","v^v<<>v<<<v<<^<v^^<>^<>^^v>v<^>><>vv<<^<^<<<vv^^^^","^v^^<^>>vv>^v><>v>^vv>v^<^vv>^^<>>>vvvv^^^^^vvvv>^",">>^v<v^>>v^^^<><^^<<^<<^>^^<^>v<^^^^<>>^><>^v^v^^^",">>vv<^^^v><>><^<><^v<^^<^>^><^v^^<^^>v^^>^>^<vv^^^",">>>vv>vv><>>>v><^^v<^<<<^<>vvv^<<>^<>>v<<^vv<^<^vv","^>^><^>^^<<><<<>^vv>>vv>vv<>v<^^><<v>^v^v^^<v>^^^^","<^^v^v^v<<>><>v><^<<^>^^<><<><^v^>^>><<><<>vvv>v^<",">>vv>^><<<><<v>^<><<^vv<^<><>^><^v^v<^v>^v<>>v^>^v","v<<<^<v>v<^>^>^<<^>><vv<v<v>^^^><><>^<^<<<<>^<><<<","<v>v<<>^^v^^>vv^^v^>^<>^>v<<>^<<<v<<>^>^^vv^><vv^<","v<^>>>^v><>><>^>^^><<<^^vv>>^v^^vv<>>>>><vv<^<<^>>","^<<<>vv<<vv^^v>^vvvv<>^>><^>v<<v>><<^^<>vv<<v^<<>>","<^vv^<v<<>>^<<>v^v<v>v^>^>^v<v^>><^><<<<<vv^<<^>>>","><>>v>^^v<v>^v<^^v>><>>><>^<^^>>^<^>><>^v^v<><>vv^","<^^><<^<^^v^v<<>>^vvvv<v>>>>><<<^><^<>v<v<^>^^<^>>","^>>v<^^^>^^>v<<>^vv^<^>^^^<>vv<^>^^<>><>><v<>v<v^>","^><^vv>>><>><v<^><<>^^<v^^vv<<>v>>^<>v<^^<^<v>vvv<",">vv>>>vv^^>v<^v^<<^^<<^v<^^^<^v>v>^>^><v<>><v>^^>v","v<^^<<v>>v<<v^v<<^^^v^vv>vv^<><v^v^^<v^^^v>^<^><^v","v<^>>^<v<><v>v^<><><<<<><^^^^^vv<<v><<^vv<v<v<^^v<","v^^>v>^<v^^<v<>^^v^>v>>^>v<<>^^><<>^^<>>><^>>v<^>>"};
	vector <int> start = { 25, 35 };
	vector<int> end = { 8,21 };
	Solution su;
	int ans = su.conveyorBelt(matrix, start, end);
	cout << ans << endl;
}