#include <regex>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return regex_match(s, regex(p));
    }
};

int main() {
    assert(Solution().isMatch("aa", "a*") == true);
}
