#include <string>
#include <cassert>
using std::string;
/**
* �ƶ���ŵ
* https://leetcode-cn.com/problems/push-dominoes/
*
* ���������
* 1��a b c : bΪL/R������a��cӰ��
* 2��a b c : bΪ.
*   ���ｫһ��������'.'��Ϊb��
*   1.a��cͬ��ʱ��b����ͬһ����
*   2.a��c����ʱ��b����
*   3.a��cΪ���ʱ��b���м䵹��
*		 ������'.'����Ϊ�������м��'.'���䣬���ΪR���ұ�ΪL
*        ������'.'����Ϊż�������м�Ϊ���ޣ����ΪR���ұ�ΪL
*
* ΪʲôҪ���ڱ���
* �������е����У���������ڱ��������ǳ�������
* R......
* L......
* ......R
* ......L
* .......
*
* �ڱ���ô�ӣ�
* ���Ĭ�ϼӸ�L���ұ�Ĭ�ϼӸ�R����������Ӱ��ԭ���С�
*/

string pushDominoes(string dominoes) {
	int n = dominoes.length();
	int i = 0;

	while (i < n)
	{
		char left = i - 1 < 0 ? 'L' : dominoes[i - 1];
		char right = 'R';
		int l = i, r = i;
		int k = i;
		while (dominoes[k] == '.' && k < n)
		{
			k++;
		}
		right = k < n ? dominoes[k] : 'R';
		if (k == i) {
			i++;
			continue;
		}
		if (left == 'L' && right == 'R') {
			//do nothing
		}
		else if (right == left) {
			while (i < k) {
				dominoes[i++] = right;
			}
		}
		else {
			int j = k - 1;
			while (i < j) {
				dominoes[i++] = 'R';
				dominoes[j--] = 'L';
			}
		}
		i = k;
	}
	return dominoes;
}

int main() {
	string s = pushDominoes("R...L");
	assert(s == "RR.LL");
}