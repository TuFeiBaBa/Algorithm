#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
public:
	RandomizedSet() {
		srand((unsigned int)time(NULL));
	}

	bool insert(int val) {
		if (indices.count(val)) return false;
		//indices.insert({ val, nums.size() });
		indices.emplace(val, nums.size());
		nums.emplace_back(val);
		return true;
	}

	bool remove(int val) {
		if (!indices.count(val)) return false;
		int index = indices[val];
		int last = nums.back();
		nums[index] = last;
		indices[last] = index;
		//最后移除旧的，否则last刚好是目标值就出问题了
		indices.erase(val);
		nums.pop_back();
		return true;
	}

	int getRandom() {
		int randomIndex = rand() % nums.size();
		return nums[randomIndex];
	}

private:
	vector<int> nums;
	unordered_map<int, int> indices;
};

int main() {

}