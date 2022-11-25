#include <string>

using namespace std;
/*
* ¼ì²â´óÐ´×ÖÄ¸ https://leetcode.cn/problems/detect-capital/description/
*/
class Solution {
public:
	bool detectCapitalUse(string word) {
		int cnt = 0;
		for (char c : word) {
			if (isupper(c)) cnt++;
		}
		return (cnt == 1 && isupper(word[0])) || cnt == 0 || cnt == word.size();
	}
};

int main() {

}