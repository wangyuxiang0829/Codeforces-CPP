#include <set>
#include <cassert>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
public:
    FindElements(TreeNode *root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
private:
    set<int> values;

    void dfs(TreeNode *root, int val) {
        if (!root) return;
        root->val = val;
        values.insert(val);
        dfs(root->left,  2 * val + 1);
        dfs(root->right, 2 * val + 2);
    }
};

int main() {
    TreeNode node1(-1);
    TreeNode node2(-1);
    node1.right = &node2;
    FindElements obj(&node1);
    assert(obj.find(1) == false);
    assert(obj.find(2) == true);
}

