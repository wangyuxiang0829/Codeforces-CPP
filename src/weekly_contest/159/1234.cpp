#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> count;
        for (auto c : s)
            count[c]++;
        for (auto c : {'Q', 'W', 'E', 'R'})
            if (count.find(c) == count.end())
                count[c] = 0;
        int need = 0;
        for (auto &p : count) {
            if (int value = p.second - s.size() / 4; value > 0) {
                p.second = value;
                need++;
            }
            else
                p.second = 0;
        }
        int window_size = 0;
        for (int i = 0, j = 0, matches = 0; j < s.size(); ++j) {
            if (--count[s[j]] == 0) matches++;
            while (matches == need) {
                if (window_size == 0 || j - i + 1 < window_size)
                    window_size = j - i + 1;
                if (++count[s[i++]] > 0) matches--;
            }
        }
        return window_size;
    }
};

int main() {
    assert(Solution().balancedString("QWER") == 0);
    assert(Solution().balancedString("QQQQ") == 3);
    assert(Solution().balancedString("QQQW") == 2);
}
