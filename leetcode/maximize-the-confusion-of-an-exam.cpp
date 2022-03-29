#include <string>
#include <cassert>
#include <queue>
using namespace std;
/**
 * ���Ե�������Ŷ�:https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/
 */
class Solution {
public:
	int maxWin(string answerKey, int k, char t) {
		int maxWin = 0;
		int curWin = 0;
		//�����ö������洢���ǾͲ���Ҫ��������
		queue<int> kPos;
		for (int i = 0; i < answerKey.size(); i++) {
			char c = answerKey[i];
			if (c == t) {
				curWin++;
			}
			else {
				if (k > 0) {
					curWin++;
					k--;
					kPos.push(i);
				}
				else {
					maxWin = max(maxWin, curWin);
					kPos.push(i);
					curWin = i - kPos.front();
					kPos.pop();
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