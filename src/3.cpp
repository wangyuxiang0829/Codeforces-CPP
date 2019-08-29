#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, ans = 0;
        int n = s.length();
        int index[128] = {};
        for (int j = 0; j < n; j++)
        {
            i = max(index[s[j]], i);
            ans = max(j - i + 1, ans);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
}
