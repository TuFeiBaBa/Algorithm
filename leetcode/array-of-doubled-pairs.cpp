#include <vector>
#include <map>

using namespace std;
class Solution {
public:
	bool canReorderDoubled(vector<int>& arr) {
		//������Ȼ����map����ǰ��������2����ֵ���������У�ż��λ��һ�����Ǻ��ؽϴ��ֵ��
		//�������ж�map���Ƿ������ı�����û�н���������map�С��������޷�����[2,4,0,0,8,1]

		//��float����Ȼ3/2=1���ᵼ�´���
		map<float, int> record;
		for (int i = 0; i < arr.size(); i++) {
			int num = arr[i];
			if (record[num * 2] > 0) {
				record[num * 2] -= 1;
			}
			else if (record[num / 2.0] > 0) {
				record[num / 2.0] -= 1;
			}
			else {
				record[num] += 1;
			}
		}
		for (map<float, int>::iterator it = record.begin(); it != record.end(); it++) {
			if (it->second != 0) return false;
		}
		return true;
	}
};

int main() {
	Solution su;
	vector<int> list{ 4, -2, 2, -4 };
	su.canReorderDoubled(list);
}