#include <cassert>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        return pathSum(root, sum, false);
    }
private:
    int pathSum(TreeNode *root, int sum, bool successive) {
        if (!root) return 0;
        int num = 0, s = sum - root->val;
        if (s == 0)
            num++;
        num += pathSum(root->left, s, true);
        num += pathSum(root->right, s, true);
        if (successive)
            return num;
        num += pathSum(root->left, sum, false);
        num += pathSum(root->right, sum, false);
        return num;
    }
};

int main() {
    TreeNode root(10);
    TreeNode node1(5);
    TreeNode node2(-3);
    TreeNode node3(3);
    TreeNode node4(2);
    TreeNode node5(11);
    TreeNode node6(3);
    TreeNode node7(-2);
    TreeNode node8(1);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.right = &node8;
    assert(Solution().pathSum(&root, 8) == 3);
}
