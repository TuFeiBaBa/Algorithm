#include <string>
#include <unordered_set>

using namespace std;

/**
* �ƽ������䣺https://leetcode.cn/problems/cracking-the-safe/
* ������Ŀ���˲������ݣ������Ӣ�İ棺https://leetcode.com/problems/cracking-the-safe/
* ��Ŀ����˼����ʵ�������ҵ����п��������봮���ַ�����Ȼ��"�ϲ�"���ǳ�����ַ�����
*
* ˼·��
*	1.����������n ��[1,4],k��[1,10]������max(k^n)=4096��������Ʋ��ؼ���û�����ƣ�max(k^n)Ҳ��10000��
*	2.��ȡÿ�����ܵ����봮�������⣺ʱ�临�Ӷ���O(k^n)��������������ԣ��ǿ��е�
*		��k=10��n=4Ϊ�����������α�������
*			void dfs(int num,int n,int k){
*				for(int i=0;i < k;i++){
*					//���n��ݹ�
*					dfs(...);
*				}
*			}
*	3.���"�ϲ�"�ַ�����û��˼·...
*
*
* Eulerian path��https://en.wikipedia.org/wiki/Eulerian_path
* ŷ���������ҽ���ÿ������Ķ���Ϊż��ʱ������ͨͼ���ž���ŷ����·������˵ŷ��������
*		   1.���������ͼ��ͼ����ͨ�ģ�ÿ���������Ⱥͳ��ȶ���ͬʱ����ͼ��ŷ����·�����磺ÿ�����㶼��k����ߺͳ���ʱ��2k��Ȼ��ż�����ʸ�ͼ��ŷ����·��
*		   2.���������ͼ��ͼ����ͨ�ģ�ÿ������Ķ���Ϊż��ʱ����ͼ��ŷ����·��
*
* ��ŷ��ͼ��ͼ����ͨ�ģ��ҽ���������ȵ㣨��ŷ��ͼ����������,ŷ��ͼҪ���Ǳ�·��,����ŷ��ͼ��Ҫ���Ǳ�·����
*
* ͼ�еĶȣ�����Ķ�(degree)������ָ�͸ö���������ı�����������ͼ�У����ַ�Ϊ��Ⱥͳ��ȡ�
*
*
* ��⣺https://leetcode.cn/problems/cracking-the-safe/solution/po-jie-bao-xian-xiang-by-leetcode-solution/
* ����أ����ǽ����е� n-1 λ����Ϊ�ڵ㣬���� k^(n-1)���ڵ㣬ÿ���ڵ��� k ����ߺͳ��ߡ������ǰ�ڵ��Ӧ����Ϊ a1a2..a(n-1)x����ô���ĵ�
* x�����߾�������a2...a(n-1)x ��Ӧ�Ľڵ㡣�������Ǵ�һ���ڵ�˳�ŵ� x �����ߵ���һ���ڵ㣬���൱������������ x��
*
* Hierholzer�㷨��������һ��ŷ��ͼ���ҳ�ŷ����·��https://blog.csdn.net/qq_19446965/article/details/104783782
*/
class Solution {
private:
	unordered_set<int> seen;
	string ans;
	int highest;
	int k;

public:
	void dfs(int node) {
		for (int x = 0; x < k; ++x) {
			int nei = node * 10 + x;
			if (!seen.count(nei)) {
				seen.insert(nei);
				//nei������ n - 1 λ�������� % highest��Ŀ����Ϊ��ȥ�����λ
				dfs(nei % highest);
				ans += (x + '0');
			}
		}
	}

	string crackSafe(int n, int k) {
		//��10..00 (��n - 1��0)
		highest = pow(10, n - 1);
		this->k = k;
		dfs(0);
		ans += string(n - 1, '0');
		return ans;
	}
};

int main() {

}