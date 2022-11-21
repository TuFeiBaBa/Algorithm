#include <string>
#include <vector>

using namespace std;
/*
* 赎金信 https://leetcode.cn/problems/ransom-note/description/
*/
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//magazine一定等于大于ransomNote
		if (ransomNote.size() > magazine.size()) return false;
		vector<int> r(26);
		for (int i = 0; i < ransomNote.size(); i++) {
			r[ransomNote[i] - 'a']++;
		}
		//可以先遍历magazine，再遍历ransomNote，那样在遍历ransonNote途中发现不满足可以提前终止
		for (int i = 0; i < magazine.size(); i++) {
			r[magazine[i] - 'a']--;
		}
		for (int n : r) {
			if (n > 0) return false;
		}
		return true;
	}
};

int main() {

}