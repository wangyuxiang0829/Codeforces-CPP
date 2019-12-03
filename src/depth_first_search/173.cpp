#include <vector>
#include <cassert>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) : i(0) {
        dfs(root);
        n = nodes.size();
    }

    int next() {
        return nodes[i++];
    }

    bool hasNext() {
        return i < n;
    }
private:
    vector<int> nodes;
    int i, n;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
};
int main() {
    TreeNode node7(7);
    TreeNode node3(3);
    TreeNode node15(15);
    TreeNode node9(9);
    TreeNode node20(20);
    node7.left = &node3;
    node7.right = &node15;
    node15.left = &node9;
    node15.right = &node20;
    BSTIterator iterator(&node7);
    assert(iterator.next() == 3);
    assert(iterator.next() == 7);
    assert(iterator.hasNext() == true);
    assert(iterator.next() == 9);
    assert(iterator.hasNext() == true);
}
