#include <fstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode *root, int L, int R) {
        if (!root) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        else if (root->val > R) return rangeSumBST(root->left, L, R);
        else return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
    }
};

int main() {
    TreeNode node1(10);
    TreeNode node2(5);
    TreeNode node3(15);
    TreeNode node4(3);
    TreeNode node5(7);
    TreeNode node6(18);

    node1.left  = &node2;
    node1.right = &node3;
    node2.left  = &node4;
    node2.right = &node5;
    node3.right = &node6;

    std::ofstream out;
    out.open("/home/wyx/test.txt", std::ofstream::app);
    out << Solution().rangeSumBST(&node1, 7, 15) << '\n';
    out.close();

    return 0;
}

