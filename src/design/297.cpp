#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode *root) {
        string s;
        destructor(root, s);
        return s;
    }

    TreeNode *deserialize(string data) {
        TreeNode *root = nullptr;
        constructor(root, data.begin(), data.end());
        return root;
    }
private:
    void destructor(const TreeNode *root, string &s) {
        if (!root) {
            s.append("!,");
            return;
        }
        s += to_string(root->val) + ',';
        destructor(root->left,  s);
        destructor(root->right, s);
    }

    typedef string::iterator striter;
    striter constructor(TreeNode *&root, striter iter, striter end) {
        if (*iter == '!') return iter + 1;
        auto next = find(iter, end, ',');
        root = new TreeNode(stoi(string(iter, next)));
        auto left  = constructor(root->left, next + 1, end);
        auto right = constructor(root->right, left + 1, end);
        return right;
    }
};

void printTree(TreeNode *root, int level) {
    if (!root) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < 4 * level; ++i)
        cout << ' ';
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

int main () {
    TreeNode node1(1000);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left  = &node2;
    node1.right = &node5;
    node2.left  = &node3;
    node2.right = &node4;

    Codec codec;
    string s = codec.serialize(&node1);
    for (auto c : s)
        cout << c;
    cout << endl;
    printTree(codec.deserialize(s), 0);
}
