#include <vector>
#include <string>
#include <iostream>


class Solution {
private:
    std::vector<std::string> result;

    void helper(int i, std::string s) {
        if (i == s.size()) {
            result.push_back(s);
            return;
        }
        helper(i + 1, s);
        if (s[i] < '0' || s[i] > '9') {
            s[i] ^= (1 << 5);
            helper(i + 1, s);
        }
    }

public:
    std::vector<std::string> letterCasePermutation(std::string S) {
        helper(0, S);
        return result;
    }

};

int main() {
    Solution s;
    auto result = s.letterCasePermutation("a1b2");
    for (const auto &s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}

