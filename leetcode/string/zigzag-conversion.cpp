#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
* Z 字形变换:https://leetcode.cn/problems/zigzag-conversion/
*
* 思路：在正常遍历字符串的过程中，按Z字形保存字符在对应的row * col 矩阵中。由于cache[row][col]不是都可能保存有字符，
*		存在明显的空间浪费。所以可以采用邻接表的形式(OS：下面代码选择邻接表，部分原因也是也不会算需要多少每行最多需要col)。
*
* 需要多少col，以及最优解：直接构造，都可参考：https://leetcode.cn/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode-solution-4n3u/
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
//				//append不行
//				//ans.append(to_string(cache[m][n]));
//				//push_back和+=均可
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
        //队列在这里没啥意义，不用也行
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