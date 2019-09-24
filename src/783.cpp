#include <tuple>
#include <limits>
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    std::tuple<int, int, int> helper(TreeNode *root) {
        int max = std::numeric_limits<int>::max();
        if (!root->left && !root->right) return std::make_tuple(max, root->val, root->val);
        int left = max, right = max, left_min = max, right_min = max;
        int current_min = root->val, current_max = root->val;
        if (root->left) {
            auto left_part = helper(root->left);
            left = std::get<0>(left_part);
            left_min = root->val - std::get<1>(left_part);
            current_min = std::get<2>(left_part);
        }
        if (root->right) {
            auto right_part = helper(root->right);
            right = std::get<0>(right_part);
            right_min = std::get<2>(right_part) - root->val;
            current_max = std::get<1>(right_part);
        }
        int min = std::min({left, right, left_min, right_min});
        return std::make_tuple(min, current_max, current_min);
    }
public:
    int minDiffInBST(TreeNode *root) {
        return std::get<0>(helper(root));
    }
};

int main() {
    TreeNode node1(4);
    TreeNode node2(2);
    TreeNode node3(6);
    TreeNode node4(1);
    TreeNode node5(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    Solution s;
    std::cout << s.minDiffInBST(&node1) << std::endl;
    return 0;
}
