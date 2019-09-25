#include <string>
#include <utility>
#include <cassert>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        int dp[n][n] = {};
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 2;
            else
                dp[i][i + 1] = 0;
        }
        for (int k = 2; k < n; ++k) {
            for (int i = 0, j = i + k; j < n; ++i, ++j) {
                if (dp[i + 1][j - 1] != 0 && s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = 0;
            }
        }
        std::pair<int, int> pair;
        int max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (dp[i][j] > max) {
                    pair.first = i;
                    pair.second = j;
                    max = dp[i][j];
                }
            }
        }
        return std::string(s.cbegin() + pair.first, s.cbegin() + pair.second + 1);
    }
};

int main() {
    Solution s;
    std::string &&tmp = s.longestPalindrome("babad");
    std::cout << tmp << std::endl;
    assert(tmp == "bab" || tmp == "aba");
    assert(s.longestPalindrome("cbbd") == "bb");
    return 0;
}

