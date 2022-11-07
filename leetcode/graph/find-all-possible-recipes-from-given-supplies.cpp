#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
/*
* �Ӹ���ԭ�������ҵ����п��������Ĳ� https://leetcode.cn/problems/find-all-possible-recipes-from-given-supplies/description/
* 
* 1.��ϰ��ʹ��map����ͼ
* 2.û���뵽��������
*/
class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		int n = recipes.size();
		unordered_map<string, vector<string>> g;
		unordered_map<string, int> record;
		for (int i = 0; i < n; i++) {
			for (auto in : ingredients[i]) {
				g[in].push_back(recipes[i]);
			}
			record[recipes[i]] = ingredients[i].size();
		}
		queue<string> q;
		vector<string> ans;
		for (auto& s : supplies) {
			q.push(s);
		}
		while (!q.empty()) {
			//auto& s�ᱨ��������queue��push�Ǵ�ĸ���������ԭֵ������pop��ʱ������ٸ���
			auto s = q.front();
			q.pop();
			if (g.find(s) != g.end()) {
				//����ͼ�ķ�Ҷ�ӽ�㣬�϶���recipes
				for (auto& r : g[s]) {
					record[r]--;
					if (record[r] == 0) {
						ans.push_back(r);
						q.push(r);
					}
				}
			}
		}
		return ans;
	}
};

int main() {

}