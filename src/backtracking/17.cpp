#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack("", 0, digits);
        return res;
    }
private:
    const string map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;

    void backtrack(string com, int i, const string &digits) {
        if (i >= digits.size()) {
            res.push_back(move(com));
            return;
        }
        for (auto c : map[digits[i] - 48]) {
            com.push_back(c);
            backtrack(com, i + 1, digits);
            com.pop_back();
        }
    }
};

ostream &operator<<(ostream &os, const vector<string> &vs) {
    for (auto s : vs)
        os << s << endl;
    return os;
}

int main() {
    cout << Solution().letterCombinations("23") << endl;
}
