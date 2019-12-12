#include <string>
#include <cassert>
using namespace std;

struct TreeNode {
    TreeNode *child[26];
    bool isWord;
};

class Trie {
public:
    Trie() : root(new TreeNode()) {
    }

    void insert(string word) {
        TreeNode *current = root;
        for (auto c : word) {
            TreeNode **child = &current->child[c - 'a'];
            if (!(*child))
                *child = new TreeNode();
            current = *child;
        }
        current->isWord = true;
    }

    bool search(string word) {
        TreeNode *node = root;
        for (auto c : word) {
            if (node->child[c - 'a'])
                node = node->child[c - 'a'];
            else
                return false;
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        TreeNode *node = root;
        for (auto c : prefix) {
            if (node->child[c - 'a'])
                node = node->child[c - 'a'];
            else
                return false;
        }
        return true;
    }
private:
    TreeNode *const root;
};

int main() {
    Trie trie;
    trie.insert("apple");
    assert(trie.search("apple") == true);
    assert(trie.search("app") == false);
    assert(trie.startsWith("app") == true);
    trie.insert("app");
    assert(trie.search("app") == true);
}
