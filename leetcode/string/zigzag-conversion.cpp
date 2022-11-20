#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
* Z ���α任:https://leetcode.cn/problems/zigzag-conversion/
*
* ˼·�������������ַ����Ĺ����У���Z���α����ַ��ڶ�Ӧ��row * col �����С�����cache[row][col]���Ƕ����ܱ������ַ���
*		�������ԵĿռ��˷ѡ����Կ��Բ����ڽӱ����ʽ(OS���������ѡ���ڽӱ�����ԭ��Ҳ��Ҳ��������Ҫ����ÿ�������Ҫcol)��
*
* ��Ҫ����col���Լ����Ž⣺ֱ�ӹ��죬���ɲο���https://leetcode.cn/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode-solution-4n3u/
*/
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (numRows == 1) return s;
//		int k = s.size();
//		vector<vector<char>> cache(numRows);
//		int row = 0;
//		int i = 0;
//		while (i < s.size()) {
//			while (row < numRows && i < s.size()) {
//				cache[row].push_back(s[i]);
//				row++;
//				i++;
//			}
//			row -= 2;
//			while (row > 0 && i < s.size()) {
//				cache[row].push_back(s[i]);
//				row--;
//				i++;
//			}
//		}
//		string ans;
//		for (int m = 0; m < cache.size(); m++) {
//			for (int n = 0; n < cache[m].size(); n++) {
//				//append����
//				//ans.append(to_string(cache[m][n]));
//				//push_back��+=����
//				//ans.push_back(cache[m][n]);
//				ans += cache[m][n];
//			}
//		}
//		return ans;
//	}
//};


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        //����������ûɶ���壬����Ҳ��
        vector<queue<char>> vq(numRows);
        int i = 0;
        while (i < s.size()) {
            for (int k = 0; k < numRows - 1 && i < s.size(); k++, i++) {
                vq[k].push(s[i]);
            }
            for (int k = numRows - 1; k > 0 && i < s.size(); k--, i++) {
                vq[k].push(s[i]);
            }
        }
        string ans;
        for (auto& q : vq) {
            while (!q.empty()) {
                auto c = q.front();
                q.pop();
                ans += c;
            }
        }
        return ans;
    }
};
int main() {
	Solution su;
	string ans = su.convert("PAYPALISHIRING", 3);
	cout << ans << endl;
}