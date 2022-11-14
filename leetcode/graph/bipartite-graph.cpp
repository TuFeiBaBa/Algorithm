#include <vector>
#include <numeric>
#include <queue>

using namespace std;
//class Solution {
//private:
//	vector<int> parent;
//	vector<int> weight;
//	int count;
//
//	int find(int x) {
//		if (parent[x] != x) {
//			parent[x] = find(parent[x]);
//		}
//		return parent[x];
//	}
//
//	void merge(int x, int y) {
//		int rootX = find(x);
//		int rootY = find(y);
//		if (rootX == rootY) return;
//		if (weight[rootX] > weight[rootY]) {
//			parent[rootY] = rootX;
//			weight[rootX] += weight[rootY];
//		}
//		else {
//			parent[rootX] = rootY;
//			weight[rootY] += weight[rootX];
//		}
//		count--;
//	}
//
//public:
//	bool isBipartite(vector<vector<int>>& graph) {
//		int n = graph.size();
//		count = n;
//		weight = vector<int>(n, 1);
//		parent = vector<int>(n);
//		iota(parent.begin(), parent.end(), 0);
//		for (int i = 0; i < n; i++) {
//			for (int j : graph[i]) {
//				merge(i, j);
//			}
//		}
//		return count == 2;
//	}
//};

//class Solution {
//public:
//    bool isBipartite(vector<vector<int>>& graph) {
//        int n = graph.size();
//        vector<int> in(n);
//        for (int i = 0; i < n; i++) {
//            for (int j : graph[i]) {
//                in[i]++;
//            }
//        }
//        for (int i : in) {
//            if (i != 2) return false;
//        }
//        return true;
//    }
//};

/*
* ����ͼ https://leetcode.cn/problems/vEAB3K/description/
* 
* һ��ʼû���⣬��Ϊ��Ҫ���жϣ�ͼ�Ƿ�պ���������ͨͼ��ֱ�����˲��鼯...
* Ȼ������ΪֻҪ�ж�ÿ���ڵ������Ƿ�Ϊ2..
* 
* [[4,1],[0,2],[1,3],[2,4],[3,0]] ����ڵ�պ�����һ�����������Ƕ���ͼ
* [[1],[0,3],[3],[1,2]]           �޻�������ÿ���ڵ����ȶ���2
* [[3],[2],[1],[0]]				  ����ͨͼ
* 
*/
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		//used[i] == 0��ʾ�ڵ�δ���ʹ�
		//used[i] == 1��ʾ�ڵ�����ɫһ
		//used[i] == -1��ʾ�ڵ�����ɫ��
		vector<int> used(n);
		//int nums = 0;
		for (int i = 0; i < n; i++) {
			//����used[i] == -1ʱ���ж�Ҳ����true
			//if (!used[i])continue;
			if (used[i] != 0) continue;
			queue<int> q;
			q.push(i);
			used[i] = 1;
			//nums++;
			while (!q.empty()) {
				int begin = q.front();
				q.pop();
				for (int end : graph[begin]) {
					if (used[end] == 0) {
						used[end] = -used[begin];
						//nums++;
						q.push(end);
					}
					else if (used[end] == used[begin]) {
						return false;
					}
				}
			}
		}
		//return nums == n;
		//�ܵ�����϶����еĶ��㶼������һ�Σ�����nums�Ƕ�����ж�
		return true;
	}
};

int main() {

}