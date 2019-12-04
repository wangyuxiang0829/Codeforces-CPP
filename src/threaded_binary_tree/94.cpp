class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        while(root) {
            if (root->left) {
                TreeNode **tmp = &root->left;
                while(*tmp)
                    tmp = &((*tmp)->right);
                *tmp = root;
                TreeNode *left = root->left;
                root->left = nullptr;
                root = left;
            }
            else {
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
