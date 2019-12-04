#include <stack>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        while(root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};
int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.right = &node2;
    node2.left = &node3;
    for (auto i : Solution().inorderTraversal(&node1))
        cout << i << ' ';
    cout << endl;
}
