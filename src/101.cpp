
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <deque>
using namespace std;
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        deque<TreeNode *> q;
        q.push_back(root);
        q.push_back(root);
        while (!q.empty())
        {
            const TreeNode *t1 = q.front();
            q.pop_front();
            const TreeNode *t2 = q.front();
            q.pop_front();
            if (!t1 && !t2)
            {
                continue;
            }
            if (!t1 || !t2)
            {
                return false;
            }
            if (t1->val != t2->val)
            {
                return false;
            }
            q.push_back(t1->left);
            q.push_back(t2->right);
            q.push_back(t1->right);
            q.push_back(t2->left);
        }
        return true;
    }
};

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(2);
    TreeNode t4(3);
    TreeNode t5(3);
    t1.left = &t2;
    t1.right = &t3;
    t2.right = &t4;
    t3.right = &t5;
    Solution s;
    s.isSymmetric(&t1);
}
