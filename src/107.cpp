#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void helper(TreeNode *root, int level, std::vector<std::vector<int>> &res) {
        if (!root)
            return;
        if (res.size() == level)
            res.push_back(std::vector<int>());
        res[level].push_back(root->val);
        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);
    }
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> res;
        helper(root, 0, res);
        return std::vector<std::vector<int>>(res.rbegin(), res.rend());
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
    auto v = s.levelOrderBottom(&root);
    for (const auto &level : v) {
        for (auto i : level) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

