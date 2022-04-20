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
		//为什么用map：
		//图是无向的，两个相连的节点a、b互为邻节点。先遍历a，再遍历b，到b时，a已经被创建过了，所以需要map记录创建的a
		//为什么不用数组：
		//虽然节点数不超过100。但由于无法知道节点的总数，所以，我们只能创建一个长度为100或101的数组，占用内存比map大。
		unordered_map<int, Node*> record;
		return dfs(node, record);
	}*/

	/**
	 * bfs思路：
	 * 1.用队列。先将头节点入队
	 * 2.while循环检测队列是否为空
	 *		1.出队队列头
	 *		2.将满足条件的入队
	 */
	Node* bfs(Node* node) {
		queue<Node*> q;
		q.push(node);
		//key用int或者Node*均可，都能唯一标识到对应的Node*
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