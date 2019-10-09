#include <string>
#include <utility>
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
    TreeNode *invertTree(TreeNode *root) {
        reverse(root);
        return root;
    }
private:
    void reverse(TreeNode *root) {
        if (!root) return;
        swap(root->left, root->right);
        reverse(root->left);
        reverse(root->right);
    }
};

void printTree(TreeNode *root, int level) {
    if (!root) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level * 4; i++)
        cout << ' ';
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

int main() {
    TreeNode node1(4);
    TreeNode node2(2);
    TreeNode node3(7);
    TreeNode node4(1);
    TreeNode node5(3);
    TreeNode node6(6);
    TreeNode node7(9);
    node1.left  = &node2;
    node1.right = &node3;
    node2.left  = &node4;
    node2.right = &node5;
    node3.left  = &node6;
    node3.right = &node7;
    printTree(Solution().invertTree(&node1), 0);
}
