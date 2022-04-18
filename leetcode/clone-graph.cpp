#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* dfs(Node* node, unordered_map<int, Node*>& record) {
		if (!node) return nullptr;
		if (record.count(node->val)) return record[node->val];
		Node* copy = new Node(node->val);
		record[node->val] = copy;
		for (int i = 0; i < node->neighbors.size(); i++) {
			copy->neighbors.push_back(dfs(node, record));
		}
		return copy;
	}

	Node* cloneGraph(Node* node) {
		unordered_map<int, Node*> record;
		return dfs(node, record);
	}
};

int main() {

}