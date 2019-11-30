#include <cassert>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        else if (!left || !right) return false;
        else
            return left->val == right->val &&
                isSame(left->left, right->right) &&
                isSame(left->right, right->left);
    }
};
int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(2);
    TreeNode node4(3);
    TreeNode node5(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;
    node3.right = &node5;
    assert(Solution().isSymmetric(&node1) == false);
}