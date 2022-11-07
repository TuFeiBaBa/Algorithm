#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
/*
* 从给定原材料中找到所有可以做出的菜 https://leetcode.cn/problems/find-all-possible-recipes-from-given-supplies/description/
* 
* 1.不习惯使用map来建图
* 2.没有想到拓扑排序
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
			//auto& s会报错：估计是queue的push是存的副本，不是原值，所以pop的时候会销毁副本
			auto s = q.front();
			q.pop();
			if (g.find(s) != g.end()) {
				//该题图的非叶子结点，肯定是recipes
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