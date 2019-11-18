#include <utility>
#include <cassert>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        return helper(root).first;
    }
private:
    pair<int, int> helper(TreeNode *root) {
        if (!root) return {-1, -1};
        auto [ld, lh] = helper(root->left);
        auto [rd, rh] = helper(root->right);
        int d = max({ld, rd, lh + rh + 2});
        int h = max(lh, rh) + 1;
        return {d, h};
    }
};

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    assert(Solution().diameterOfBinaryTree(&node1) == 3);
}

