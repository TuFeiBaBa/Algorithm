#include <vector>
#include <string>

using namespace std;
/*
* �ظ������ַ��� https://leetcode.cn/problems/repeated-substring-pattern/description/
*/
class Solution {
private:
	vector<int> next;
	void buildNext(string& s) {
		int k = 0;
		int i = 1;
		while (i < s.size()) {
			if (s[k] == s[i]) {
				next[i] = k + 1;
				i++;
				k++;
			}
			else if (k > 0) {
				k = next[k - 1];
			}
			else {
				i++;
			}
		}
	}

	bool kmp(string s, string p) {
		//ʹ��reserveʱ��û�б���ʼ��Ϊ0
		next.reserve(p.size());
		for (int i = 0; i < p.size(); i++) next[i] = 0;
		buildNext(p);
		// int s_pos = 0,pos = 0;
		// while(s_pos < s.size()){
		//     if(s[s_pos] == p[pos]){
		//         s_pos++;
		//         pos++;
		//     // }else if(next[pos - 1] > 0){
		//     }else if(pos > 0) {
		//         pos = next[pos - 1];
		//     }else{
		//         s_pos++;
		//     }

		//     if(pos == p.size()){
		//         // if(s_pos == p.size()){
		//         //     return true;
		//         // }else{
		//         //     return false;
		//         // }
		//         if(s_pos > p.size() && s_pos < s.size()) return true;
		//         pos = next[pos - 1];
		//     }
		// }

		//����ע�͵��Ǳ�׼��kmp�㷨ʵ��
		//����Ĵ�������һ���Ķ���s_pos�޶���0 < s_pos < s.size() - 1
		//��Ϊ����"aaaa"��"aa"��"abcabc"��"abc"�������Ƿ�����������ظ����ַ�����[0,p.size() - 1]��[p.size(),s.size() - 1]
		//��Ȼ�ǵ���pģʽ���ģ�����Ҫȥͷȥβ
		int s_pos = 1, pos = 0;
		while (s_pos < s.size() - 1) {
			if (s[s_pos] == p[pos]) {
				s_pos++;
				pos++;
			}
			else if (pos > 0) {
				pos = next[pos - 1];
			}
			else {
				s_pos++;
			}

			if (pos == p.size()) {
				return true;
			}
		}
		return false;
	}
public:
	bool repeatedSubstringPattern(string s) {
		return kmp(s + s, s);
	}
};

int main() {

}