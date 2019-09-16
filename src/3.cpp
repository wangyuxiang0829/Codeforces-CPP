#include <string>
#include <unordered_set>
#include <cassert>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_length = 0;
        std::unordered_set<char> set;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                max_length = std::max(max_length, j - i + 1);
            }
            else {
                while (set.find(s[j]) != set.end()) {
                    set.erase(s[i++]);
                }
                set.insert(s[j]);
            }
        }
        return max_length;
    }
};

int main() {
    Solution s;
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
    return 0;
}

