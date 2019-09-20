#include <string>
#include <cassert>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        if (n == 0 || n == 1)
            return 0;
        int dp[n] = {};
        if (s[0] == '(' && s[1] == ')') dp[1] = 2;
        int max = dp[1];
        for (int i = 2; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = dp[i - 2] + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                max = dp[i] > max ? dp[i] : max;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    assert(s.longestValidParentheses("())") == 2);
    assert(s.longestValidParentheses(")()())") == 4);
    return 0;
}

