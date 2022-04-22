#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;
/*
* https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/
* 思路：
* 1.先按要求处理任务，对于第i个任务
*	1.服务器i刚好有空，让它处理
*	2.服务器i没空
*		1.服务器[i + 1,last]有一个有空
*		2.服务器[first,i-1]有一个有空
*		3.都没空，抛弃任务，不处理
*		综上，用set来存储空闲服务器即可
* 2.如何检测服务器最新的空闲情况？
*	1.在处理任务i的时候，先查询一下忙碌结束时间不大于arrival[i]的服务器。
*	综上，忙碌的服务器，用优先队列来存储即可。优先队列的排序规则是？最小堆，忙碌结束时间最快的排前面。
* 
* 问题点：
* 1.C++的优先队列默认是最大堆。最小堆写法比较麻烦。
* 2.时间复杂度不会算:
*	1.set是红黑树结构，它的增删的时间复杂度都是O(logn)
*	2.优先队列是堆结构，即完全二叉树。增删的时间复杂度是O(logn)
*   综上，整体的时间复杂度是O(klogk + nlogk),即O((k + n)logk)
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