#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int answer = 0;
private:
    int helper(const TreeNode *root) {
        if (!root) return 0;
        int left_start_path = helper(root->left);
        int right_start_path = helper(root->right);
        int left_path = 0, right_path = 0;
        if (root->left && root->val == root->left->val) {
            left_path = left_start_path + 1;
        }
        if (root->right && root->val == root->right->val) {
            right_path = right_start_path + 1;
        }
        answer = std::max(answer, left_path + right_path);
        return std::max(left_path, right_path);
    }

public:
    int longestUnivaluePath(TreeNode *root) {
        helper(root);
        return answer;
    }
};

int main() {
    Solution s;
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(5);
    TreeNode node3(1);
    TreeNode node4(1);
    TreeNode node5(5);
    root.left   = &node1;
    root.right  = &node2;
    node1.left  = &node3;
    node1.right = &node4;
    node2.right = &node5;
    std::cout << s.longestUnivaluePath(&root) << std::endl;
    return 0;
}
