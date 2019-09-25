#include <vector>
#include <unordered_map>

struct Node {
    int val;
    std::vector<Node *> neighbors;

    Node() {}
    Node(int _val, std::vector<Node *> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
    std::unordered_map<Node *, Node *> already_cloned;

public:
    Node *cloneGraph(Node *node) {
        if (already_cloned.find(node) != already_cloned.end()) return already_cloned[node];
        auto cloned_node = new Node(node->val, std::vector<Node *>());
        already_cloned[node] = cloned_node;
        for (auto iter : node->neighbors) cloned_node->neighbors.push_back(cloneGraph(iter));
        return cloned_node;
    }
};

