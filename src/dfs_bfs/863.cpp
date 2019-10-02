#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        get_parent(root);
        vector<int> res;
        dfs(target, 0, K, res);
        return res;
    }
private:
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_set<TreeNode *> searched;

    void get_parent(TreeNode *root) {
        if (root->left) {
            parent[root->left] = root;
            get_parent(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            get_parent(root->right);
        }
    }

    void dfs(TreeNode *vertex, int level, int K, vector<int> &res) {
        if (level >= K) {
            res.push_back(vertex->val);
            return;
        }
        searched.insert(vertex);
        if (vertex->left && searched.find(vertex->left) == searched.end()) dfs(vertex->left, level + 1, K, res);
        if (vertex->right && searched.find(vertex->right) == searched.end()) dfs(vertex->right, level + 1, K, res);
        if (parent.find(vertex) != parent.end() && searched.find(parent[vertex]) == searched.end()) dfs(parent[vertex], level + 1, K, res);
    }
};

int main() {
//    TreeNode node1(3);
//    TreeNode node2(5);
//    TreeNode node3(1);
//    TreeNode node4(6);
//    TreeNode node5(2);
//    TreeNode node6(0);
//    TreeNode node7(8);
//    TreeNode node8(7);
//    TreeNode node9(4);
//
//    node1.left = &node2;
//    node1.right = &node3;
//    node2.left = &node4;
//    node2.right = &node5;
//    node3.left = &node6;
//    node3.right = &node7;
//    node5.left = &node8;
//    node5.right = &node9;

    TreeNode node1(0);
    TreeNode node2(1);
    TreeNode node3(3);
    TreeNode node4(2);

    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;

    auto result = Solution().distanceK(&node1, &node1, 2);
    for (auto i : result)
        cout << i << endl;
}

