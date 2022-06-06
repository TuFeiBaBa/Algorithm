#include <vector>
#include <unordered_map>
using namespace std;

/*
* �Ƴ�����ͬ�л�ͬ��ʯͷ: https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column
* ��⣺https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/solution/947-yi-chu-zui-duo-de-tong-xing-huo-tong-ezha/
*
* ����˼�룺һ�����԰�һ����ͨͼ������ж�������������ɾ��ֻʣ��һ�����㡣
*			���ԣ��������Ƴ���ʯͷ�ĸ��� = ����ʯͷ�ĸ��� - ��ͨ�����ĸ�����������ͨ�����ĸ���������ʹ�ò��鼯��
*
* ʹ�ò��鼯�ļ����ѵ㣺
*		1.��ʲô������parent�������鲻�У���֪���ж��ٸ���ͬ��x/y
*		2.��ô�ϲ������������x��y��ͬʱ���������������ͨ�ġ���������Ƕ���������кϲ��������߼����ô���parentҲ���ö��塣
*					����˼·��ÿ������ʵ���Ƕ����Կ�����һ����ͨͼ������x��y�����Ȼͬ����һ�����ϡ�����x��y�������ϲ���
*					����ÿ���������x��y���кϲ���
*		3.��ô����x��y���꣺ʯͷ��λ���ǡ��������ԣ���ά���������鼯�ĵײ��ǡ�һά���项�������ڲ��鼯��Ӧ��������ֺ��������أ�
*		4.count��ô����
*
*/
class Solution {
private:
	int count;
	unordered_map<int, int> parent;
	unordered_map<int, int> weight;
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y) {
		if (parent.count(x) == 0) {
			parent[x] = x;
			weight[x] = 1;
			count++;
		}
		if (parent.count(y) == 0) {
			parent[y] = y;
			weight[y] = 1;
			count++;
		}
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;
		if (weight[rootX] > weight[rootY]) {
			parent[rootY] = rootX;
			weight[rootX] += weight[rootY];
		}
		else {
			parent[rootX] = rootY;
			weight[rootY] += weight[rootX];
		}
		count--;
	}

public:
	int removeStones(vector<vector<int>>& stones) {
		for (int i = 0; i < stones.size(); i++) {
			merge(stones[i][0], stones[i][1] + 10000);
		}
		return stones.size() - count;
	}
};

int main() {

}