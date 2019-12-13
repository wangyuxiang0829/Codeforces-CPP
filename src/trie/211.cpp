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

    bool search(const string &word) {
        return search(word, 0, root);
    }

private:
    bool search(const string &word, const int i, TreeNode *node) {
        if (i >= word.size()) return node->isWord;
        char c = word[i];
        if (c == '.') {
            for (int k = 0; k < 26; k++) {
                if (node->child[k])
                    if (search(word, i + 1, node->child[k]))
                        return true;
            }
            return false;
        }
        else {
            if (node->child[c - 'a'])
                return search(word, i + 1, node->child[c - 'a']);
            else
                return false;
        }
    }

    TreeNode *const root;
};

class WordDictionary {
public:
    WordDictionary() {
    }

    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
private:
    Trie trie;
};

int main() {
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    assert(w.search("pad") == false);
    assert(w.search("bad") == true);
    assert(w.search(".ad") == true);
    assert(w.search("b..") == true);
}
