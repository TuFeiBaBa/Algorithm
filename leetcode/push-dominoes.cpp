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
*   1.aΪL��cΪR��b����
*   2.aΪL��cΪL��bΪL
*   3.aΪR��cΪL��b����
*   4.aΪR��cΪR��bΪR
*   5.cΪ'.'���޷��ж�b�ķ�������ǰ������ֱ��������һ����'.'��c`��
*        1�����c`ΪL����ʱ��Ҫ����ߵ�һ����Ϊ'.'�����
*           ��1��ΪR���м���ڵĶ������'.'
*               ������'.'����Ϊ�������м��'.'���䣬���ΪR���ұ�ΪL
*               ������'.'����Ϊż�������м�Ϊ���ޣ����ΪR���ұ�ΪL
*           ��2��ΪL���м���ڵĶ������'.'��ΪL
*        2�����c`ΪR��bҪ����ߵ�һ����Ϊ'.'�����
*           ��1��ΪL���м���ڵĶ������'.'����
*           ��2��ΪR���м���ڵĶ������'.'��ΪR
*
* �����������2����ĵ���㣬�ǽ�������'.'��Ϊһ�������������߼�������Ը��ǵ����������2����1��2��3��4�������
* ���ԣ�����ֻ��Ҫ�����������������
* 1��a b c : bΪL/R������a��cӰ��
* 2��cΪ'.'���޷��ж�b�ķ���....
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
* ��߼Ӹ�L���ұ߼Ӹ�R����������Ӱ��ԭ���С�
*/

string pushDominoes(string dominoes) {
	int n = dominoes.length();
	int i = 0;
	
	while (i < n)
	{
		char left = i - 1 < 0? 'L':dominoes[i - 1];
		char right = 'R';
		int l = i, r = i;
		int k = i;
		while (dominoes[k] == '.' && k + 1 < n)
		{
			if (dominoes[k + 1] == '.') {
				k++;
			}
			else {
				right = dominoes[k + 1];
				break;
			}
		}
		if (k == i) {
			if (dominoes[k] == '.') {
				if (left == 'R' && right == 'R') {
					dominoes[k] = 'R';
				}
				else if (left == 'L' && right == 'L') {
					dominoes[k] = 'L';
				}
			}
			i++;
		}
		else {
			//�����С�����iΪ1��kΪ2��center��Ϊ1�ˡ�����1û�б����ġ�
			//int center = (k + i) / 2;
			//while (i <= k) {
			//	if (right == 'L') {
			//		if (left == 'R') {
			//			if (i < center) {
			//				dominoes[i] = 'R';
			//			}
			//			else if (i > center) {
			//				dominoes[i] = 'L';
			//			}
			//		}
			//		else
			//		{
			//			dominoes[i] = 'L';
			//		}
			//	}
			//	else {
			//		if (left == 'L') {
			//			i = k;
			//			break;
			//		}
			//		else {
			//			dominoes[i] = 'R';
			//		}
			//	}
			//	i++;
			//}
			int next = k + 1;
			while (i < k) {
				if (right == 'L' && left == 'R') {
						dominoes[i++] = 'R';
						dominoes[k--] = 'L';
					
				}
				else if (right == 'L' && left == 'L') {
					while (i <= k) {
						dominoes[i++] = 'L';
					}
				}
				else if (right == 'R' && left == 'R') {
					while (i <= k) {
						dominoes[i++] = 'R';
					}
				}
				else
				{
					break;
				}
			}
			i = next;
		}
	}
	return dominoes;
}

int main() {
	string s = pushDominoes("R...L");
	assert(s == "RR.LL");
}