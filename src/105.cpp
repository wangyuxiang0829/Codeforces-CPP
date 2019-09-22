#include <vector>
#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void buildRoot(const std::vector<int> &preorder, const std::vector<int> &inorder, TreeNode *&root) {
        if (!preorder.size()) return;
        root = new TreeNode(preorder.front());
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder.front()) {
                buildRoot(std::vector<int>(preorder.begin() + 1, preorder.begin() + 1 + i),
                        std::vector<int>(inorder.begin(), inorder.begin() + i), root->left);
                buildRoot(std::vector<int>(preorder.begin() + 1 + i, preorder.end()),
                        std::vector<int>(inorder.begin() + i + 1, inorder.end()), root->right);
                return;
            }
        }
    }

public:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        TreeNode *root = nullptr;
        buildRoot(preorder, inorder, root);
        return root;
    }
};

void traversing(TreeNode *root, unsigned level) {
    if (!root) return;
    traversing(root->right, level + 1);
    std::cout << std::string(4 * level, ' ') << root->val << std::endl;
    traversing(root->left, level + 1);
}

int main() {
    Solution s;
    traversing(s.buildTree(std::vector<int>({3, 9, 20, 15, 7}), std::vector<int>({9, 3, 15, 20, 7})), 0);
    return 0;
}

