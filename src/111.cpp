#include <utility>
#include <deque>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        std::deque<std::pair<TreeNode *, int>> q;
        q.push_back(std::make_pair(root, 1));
        auto current_depth = 0;
        while (!q.empty()) {
            auto pair = q.front();
            q.pop_front();
            auto node = pair.first;
            current_depth = pair.second;
            if (!node->left && !node->right)
                break;
            if (node->left)
                q.push_back(std::make_pair(node->left, current_depth + 1));
            if (node->right)
                q.push_back(std::make_pair(node->right, current_depth + 1));
        }
        return current_depth;
    }
};

int main() {
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    Solution s;
    std::cout << s.minDepth(&root) << std::endl;
    return 0;
}
