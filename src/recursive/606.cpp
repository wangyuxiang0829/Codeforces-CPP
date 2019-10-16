#include <sstream>
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
    string tree2str(TreeNode *t) {
        ostringstream os;
        dfs(os, t);
        string s(os.str());
        return s.substr(1, s.size() - 2);
    }
private:
    void dfs(ostringstream &os, TreeNode *root) {
        if (!root) os << "()";
        else if (!root->left && !root->right)
            os << '(' << root->val << ')';
        else if (root->left && !root->right) {
            os << '(' << root->val;
            dfs(os, root->left);
            os << ')';
        }
        else {
            os << '(' << root->val;
            dfs(os, root->left);
            dfs(os, root->right);
            os << ')';
        }
    }
};

int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    t1.left = &t2;
    t1.right = &t3;
    t2.right = &t4;
    cout << Solution().tree2str(&t1) << endl;
}
