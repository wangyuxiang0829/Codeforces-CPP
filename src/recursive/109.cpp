#include <vector>
#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void buildRoot(const std::vector<int> &v, TreeNode *&root) {
        if (v.empty()) return;
        int n = v.size();
        root = new TreeNode(v[n / 2]);
        buildRoot(std::vector<int>(v.begin(), v.begin() + n / 2), root->left);
        buildRoot(std::vector<int>(v.begin() + 1 + n / 2, v.end()), root->right);
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        std::vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        TreeNode *root = nullptr;
        buildRoot(v, root);
        return root;
    }
};

void printTree(TreeNode *root, int numSpace) {
    if (!root) return;
    printTree(root->right, numSpace + 1);
    std::cout << std::string(numSpace * 4, ' ') << root->val << std::endl;
    printTree(root->left, numSpace + 1);
}

int main() {
    ListNode node1(-10);
    ListNode node2(-3);
    ListNode node3(0);
    ListNode node4(5);
    ListNode node5(9);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    printTree(Solution().sortedListToBST(&node1), 0);
}

