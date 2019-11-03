#include <cassert>
class Solution {
public:
    int tribonacci(int n) {
        int dp[38] = {0, 1, 1};
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};

int main() {
    assert(Solution().tribonacci(25) == 1389537);
}
