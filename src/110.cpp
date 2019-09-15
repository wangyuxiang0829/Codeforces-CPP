#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    auto helper(TreeNode *root) {
        if (!root)
            return std::make_pair(true, 0);
        auto lpair = helper(root->left);
        auto rpair = helper(root->right);
        bool flag = lpair.first && rpair.first &&
            std::abs(lpair.second - rpair.second) <= 1;
        int height = std::max(lpair.second, rpair.second) + 1;
        return std::make_pair(flag, height);
    }

public:
    bool isBalanced(TreeNode *root) {
        return helper(root).first;
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
    assert(s.isBalanced(&root) == true);
    return 0;
}
