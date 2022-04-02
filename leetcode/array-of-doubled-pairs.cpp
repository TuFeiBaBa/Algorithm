#include <vector>
#include <map>

using namespace std;
class Solution {
public:
	bool canReorderDoubled(vector<int>& arr) {
		//先排序？然后用map保存前半截数组的2倍数值？（不可行，偶数位不一定都是后半截较大的值）
		//先排序：判断map里是否有它的倍数。没有将该数存入map中。不排序无法处理：[2,4,0,0,8,1]

		//用float，不然3/2=1，会导致错误
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