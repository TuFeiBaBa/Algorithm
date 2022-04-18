#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;
/*
* https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/
*/
class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		set<int> avaible;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> queue;
		vector<int> statistics_list(k);

		for (int i = 0; i < k; i++) {
			//不支持语法
			//avaible[i]= i;
			avaible.emplace(i);
		}

		for (int i = 0; i < arrival.size(); i++) {
			while (!queue.empty() && arrival[i] >= queue.top().first) {
				avaible.emplace(queue.top().second);
				queue.pop();
			}

			if (avaible.empty()) {
				continue;
			}
			//错误写法：iterator<int> 
			//注意要 % k
			set<int>::iterator target = avaible.lower_bound(i % k);
			if (target == avaible.end()) {
				target = avaible.begin();

			}
			//不能先移除，不然 *target 会报错：
			//cannot dereference value-initialized map/set iterator
			//avaible.erase(target);
			//获取值
			statistics_list[*target] += 1;
			queue.emplace(arrival[i] + load[i], *target);
			avaible.erase(target);
		}

		int maxRequest = *max_element(statistics_list.begin(), statistics_list.end());
		vector<int> ret;
		for (int i = 0; i < k; i++) {
			if (statistics_list[i] == maxRequest) {
				ret.push_back(i);
			}
		}
		return ret;
	}
};

int main() {
	Solution su;
	int k = 3;
	vector<int> arrival{ 1 };
	vector<int> load{ 1000000000 };
	vector<int> ret = su.busiestServers(3, arrival, load);
	//cout << ret << endl;
	std::for_each(ret.begin(), ret.end(), [](const auto& i) {std::cout << i << " "; });
	return 0;
}