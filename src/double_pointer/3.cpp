#include <string>
#include <bitset>
#include <cassert>
#define max(i, j) (i > j ? i : j)
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<256> exist_char;
        int max_length = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            while(exist_char[s[j]])
                exist_char.reset(s[i++]);
            max_length = max(j - i + 1, max_length);
            exist_char.set(s[j]);
        }
        return max_length;
    }
};
int main() {
    assert(Solution().lengthOfLongestSubstring("abcabcbb") == 3);
}
