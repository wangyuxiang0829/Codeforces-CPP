#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), result = n, dp[n][n];
        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1] ? 1 : 0);
            result += dp[i][i + 1];
        }
        dp[n - 1][n - 1] = 1;
        for (int k = 2; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                if (s[i] == s[i + k] && dp[i + 1][i + k - 1])
                    dp[i][i + k] = 1;
                else
                    dp[i][i + k] = 0;
                result += dp[i][i + k];
            }
        }
        return result;
    }
};

int main() {
    assert(Solution().countSubstrings("aaa") == 6);
}
