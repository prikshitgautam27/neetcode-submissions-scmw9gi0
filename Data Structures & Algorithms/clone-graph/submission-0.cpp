#include <vector>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
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
*/

class Solution {
public:
    // Hash map to store original node -> cloned node mapping
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If node is already cloned, return the cloned instance
        if (copies.find(node) != copies.end()) {
            return copies[node];
        }

        // Create a deep copy of the current node
        Node* copy = new Node(node->val);
        copies[node] = copy;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};
