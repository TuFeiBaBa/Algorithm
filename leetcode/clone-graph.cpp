#include <unordered_map>
#include <vector>
#include <queue>
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
	/*Node* dfs(Node* node, unordered_map<int, Node*>& record) {
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
	}*/

	Node* bfs(Node* node) {
		queue<Node*> q;
		q.push(node);
		//这里也和dfs有差异
		unordered_map<Node*, Node*> record;
		record[node] = new Node(node->val);
		while (!q.empty()) {
			Node* n = q.front();
			q.pop();
			for (Node* neighbor : n->neighbors) {
				if (record.find(neighbor) == record.end()) {
					record[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				record[n]->neighbors.emplace_back(record[neighbor]);
			}
		}
		return record[node];
	}

	Node* cloneGraph(Node* node) {
		if (node == nullptr) return nullptr;
		return bfs(node);
	}
};

int main() {

}