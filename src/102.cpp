#include <vector>
#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (!root)
            return result;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            result.push_back(std::vector<int>());
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                result.rbegin()->push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    auto v = s.levelOrder(&root);
    for (const auto &level : v) {
        for (auto i : level) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

