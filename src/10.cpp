#include <string>
#include <cassert>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (p.empty()) return s.empty();
        bool current_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if (p.size() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (current_match && isMatch(s.substr(1), p));
        else
            return current_match && isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution s;
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "a*") == true);
    assert(s.isMatch("ab", ".*") == true);
    return 0;
}

