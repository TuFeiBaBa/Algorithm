#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;
/*
* �޷�AC�� 8  [[4,6],[5,2],[3,5],[7,5],[7,6]]
* ������ʹ����sort����������ڣ������������㣬����ͬ���ڱߡ�������һ���Ǻ��ڱ����ĵ����ڣ���һ�����ǡ����򲢲���������һ�㡣
*/
//class Solution {
//public:
//	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
//		vector < pair<int, int>> record(n, pair<int, int>());
//		unordered_map<int, unordered_set<int>> m;
//		for (auto& edge : roads) {
//			record[edge[0]].first++;
//			record[edge[0]].second = edge[0];
//			record[edge[1]].first++;
//			record[edge[1]].second = edge[1];
//			m[edge[0]].emplace(edge[1]);
//			m[edge[1]].emplace(edge[0]);
//		}
//		sort(record.begin(), record.end(), greater<pair<int,int>>());
//		int ans = record[0].first + record[1].first;
//		if (m[record[0].second].find(record[1].second) != m[record[0].second].end()) ans--;
//		return ans;
//	}
//};

/**
* ��������� https://leetcode.cn/problems/maximal-network-rank/description/
*/
class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		//Ϊ������Ҫ���������
		if (roads.empty()) return 0;
		vector<int> citys(n);
		unordered_set<int> set;
		for (auto& road : roads) {
			citys[road[0]]++;
			citys[road[1]]++;
			//��ȷ��λ��������ȼ�������������������(road[0] << 16)
			//|��������+�Ƿ���ã�����һ����Ч�ʣ�
			set.emplace((road[0] << 16) | road[1]);
			set.emplace((road[1] << 16) | road[0]);
		}
		//�ǵ��ȳ�ʼ��
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, set.find((i << 16) | j) == set.end() ? citys[i] + citys[j] : citys[i] + citys[j] - 1);
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> roads = { {0,1},{0,3},{1,2},{1,3} };
	Solution su;
	int ans = su.maximalNetworkRank(4, roads);
	cout << ans << endl;
}