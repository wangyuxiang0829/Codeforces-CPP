#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return {};
        dfs(root, string());
        return result;
    }
private:
    vector<string> result;
    void dfs(TreeNode *root, string s) {
        s += string("->") + to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(s.substr(2));
            return;
        }
        if (root->left) dfs(root->left, s);
        if (root->right) dfs(root->right, s);
    }
};

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node5;
    for (auto s : Solution().binaryTreePaths(&node1))
        cout << s << endl;
}
