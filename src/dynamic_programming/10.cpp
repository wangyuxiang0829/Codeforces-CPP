#include <vector>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        for (int i = 2; i <= n; i += 2)
            dp[i][0] = (p[i - 1] == '*' && dp[i - 2][0]);
        for (int i = 1; i <= n; i++) {
            char c = p[i - 1];
            switch (c) {
                case '*':
                    for (int j = 1; j <= m; j++) {
                        if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
                            dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 2][j];
                        else
                            dp[i][j] = dp[i - 2][j];
                    }
                    break;
                case '.':
                    for (int j = 1; j <= m; j++)
                        dp[i][j] = dp[i - 1][j - 1];
                    break;
                default:
                    for (int j = 1; j <= m; j++)
                        dp[i][j] = (c == s[j - 1] && dp[i - 1][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main() {
    assert(Solution().isMatch("aaa", "ab*ac*a") == true);
}
