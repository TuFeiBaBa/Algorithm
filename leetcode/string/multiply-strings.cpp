#include <string>
#include <vector>

using namespace std;
/*
* �ַ������ https://leetcode.cn/problems/multiply-strings/description/
*/
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0") return "0";
//		reverse(num1.begin(), num1.end());
//		reverse(num2.begin(), num2.end());
//		string ans;
//		int c = 0;
//		for (int i = 0; i < num1.size(); i++) {
//			string t;
//			for (int j = 0; j < num2.size(); j++) {
//				int r = (num1[i] - '0') * (num2[j] - '0') + c;
//				t += r % 10 + '0';
//				c = r / 10;
//			}
//			if (c > 0) t += c + '0';
//			c = 0;
//
//			string old = ans;
//			ans = "";
//			for (int k = 0; k < max(old.size(), t.size() + i); k++) {
//				int m = k < old.size() ? old[k] - '0' : 0;
//				int n = k - i >= 0 && k - i < t.size() ? t[k - i] - '0' : 0;
//				ans += (m + n + c) % 10 + '0';
//				c = (m + n + c) / 10;
//			}
//			if (c > 0) ans += c + '0';
//			c = 0;
//		}
//		reverse(ans.begin(), ans.end());
//		return ans;
//	}
//};

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		int m = num1.size();
		int n = num2.size();
		//���������,�����m + nλ��
		vector<int> res(m + n);
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				//��ǰλ���� i + j + 1(��λ)
				int sum = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
				res[i + j + 1] = sum % 10;
				//��һ��λ���� i + j(��λ)
				res[i + j] += sum / 10;
			}
		}
		string ans;
		for (int i = res[0] == 0 ? 1 : 0; i < res.size(); i++) {
			ans += res[i] + '0';
		}
		return ans;
	}
};

int main() {

}