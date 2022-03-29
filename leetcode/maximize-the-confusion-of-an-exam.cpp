#include <string>
#include <cassert>
using namespace std;
/**
 * 考试的最大困扰度:https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/
 */
class Solution {
public:
	int maxWin(string answerKey, int k, char t) {
		int maxWin = 0;
		int curWin = 0;
		int lastReplacePos = -1;
		for (int i = 0; i < answerKey.size(); i++) {
			char c = answerKey[i];
			if (c == t) {
				curWin++;
			}
			else {
				if (k > 0) {
					curWin++;
					k--;
					if (lastReplacePos == -1) lastReplacePos = i;
				}
				else {
					maxWin = max(maxWin, curWin);
					curWin = i - lastReplacePos;
					for (int j = lastReplacePos + 1; j <= i; j++) {
						if (answerKey[j] != t) {
							lastReplacePos = j;
							break;
						}
					}
				}
			}
		}
		return max(maxWin, curWin);
	}

	int maxConsecutiveAnswers(string answerKey, int k) {
		int a = maxWin(answerKey, k, 'T');
		int b = maxWin(answerKey, k, 'F');
		return max(a, b);
	}
};

int main() {
	Solution so;
	int max = so.maxConsecutiveAnswers("TTFTTFTT", 1);
	assert(max == 5);
}