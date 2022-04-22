#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;
/*
* https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/
* ˼·��
* 1.�Ȱ�Ҫ�������񣬶��ڵ�i������
*	1.������i�պ��пգ���������
*	2.������iû��
*		1.������[i + 1,last]��һ���п�
*		2.������[first,i-1]��һ���п�
*		3.��û�գ��������񣬲�����
*		���ϣ���set���洢���з���������
* 2.��μ����������µĿ��������
*	1.�ڴ�������i��ʱ���Ȳ�ѯһ��æµ����ʱ�䲻����arrival[i]�ķ�������
*	���ϣ�æµ�ķ������������ȶ������洢���ɡ����ȶ��е���������ǣ���С�ѣ�æµ����ʱ��������ǰ�档
* 
* ����㣺
* 1.C++�����ȶ���Ĭ�������ѡ���С��д���Ƚ��鷳��
* 2.ʱ�临�ӶȲ�����:
*	1.set�Ǻ�����ṹ��������ɾ��ʱ�临�Ӷȶ���O(logn)
*	2.���ȶ����Ƕѽṹ������ȫ����������ɾ��ʱ�临�Ӷ���O(logn)
*   ���ϣ������ʱ�临�Ӷ���O(klogk + nlogk),��O((k + n)logk)
*/
class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		set<int> avaible;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> queue;
		vector<int> statistics_list(k);

		for (int i = 0; i < k; i++) {
			//��֧���﷨
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
			//����д����iterator<int> 
			//ע��Ҫ % k
			set<int>::iterator target = avaible.lower_bound(i % k);
			if (target == avaible.end()) {
				target = avaible.begin();

			}
			//�������Ƴ�����Ȼ *target �ᱨ��
			//cannot dereference value-initialized map/set iterator
			//avaible.erase(target);
			//��ȡֵ
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