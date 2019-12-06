/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumOfLeftLeaves(root, false);
    }
private:
    int sumOfLeftLeaves(TreeNode *root, bool left) {
        int cur = 0;
        if (!root->left && !root->right) {
            if (left) {
                cur += root->val;
            }
        }
        if (root->left) {
            cur += sumOfLeftLeaves(root->left, true);
        }
        if (root->right) {
            cur += sumOfLeftLeaves(root->right, false);
        }
        return cur;
    }
};
