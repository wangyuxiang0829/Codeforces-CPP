#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (steps == 1 || arrLen == 1) return 1;
        int n = min(steps + 1, arrLen);
        vector<vector<int>> dp(steps, vector<int>(n));
        dp[0][0] = 1, dp[0][1] = 1;
        for (int i = 1; i < steps; i++) {
            for (int j = 0; j < n; j++) {
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
                if (j + 1 < n) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
        return dp[steps - 1][0];
    }
private:
    static constexpr int MOD = static_cast<int>(1e9 + 7);
};

int main() {
    assert(Solution().numWays(3, 2) == 4);
}
