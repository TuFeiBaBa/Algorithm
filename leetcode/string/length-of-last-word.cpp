#include <string>

using namespace std;

//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int k = 0;
//        int len = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') {
//                k++;
//                len = k;
//            }
//            if (s[i] == ' ') {
//                k = 0;
//            }
//        }
//        return len;
//    }
//};
/*
* 最后一个单词的长度 https://leetcode.cn/problems/length-of-last-word/description/
* 
* 上面解法是从头开始找，其实从尾部开始找即可
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				len++;
			}
			if (s[i] == ' ' && len != 0) {
				break;
			}
		}
		return len;
	}
};

int main() {

}