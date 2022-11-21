#include <string>
#include <vector>

using namespace std;
/*
* ����� https://leetcode.cn/problems/ransom-note/description/
*/
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//magazineһ�����ڴ���ransomNote
		if (ransomNote.size() > magazine.size()) return false;
		vector<int> r(26);
		for (int i = 0; i < ransomNote.size(); i++) {
			r[ransomNote[i] - 'a']++;
		}
		//�����ȱ���magazine���ٱ���ransomNote�������ڱ���ransonNote;�з��ֲ����������ǰ��ֹ
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