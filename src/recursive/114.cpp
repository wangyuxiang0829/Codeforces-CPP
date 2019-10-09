#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        if (!root->left) {
            flatten(root->right);
            return;
        }
        TreeNode *tmp = root->left;
        while (tmp->right)
            tmp = tmp->right;
        tmp->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        flatten(root->right);
    }
};

void printTree(TreeNode *root) {
    if (!root) return;
    cout << root->val << endl;
    printTree(root->right);
}

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node5(5);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node6(6);

    node1.left = &node2;
    node1.right = &node5;
    node2.left = &node3;
    node2.right = &node4;
    node5.right = &node6;

    Solution().flatten(&node1);

    printTree(&node1);
}
