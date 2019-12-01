#include <string>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        if (k == n) return 0;
        vector<vector<int>> cost(n, vector<int>(n));
        for (int j = 0; j < n; j++)
            cost[j][j] = 0;
        for (int j = 0; j < n - 1; j++)
            cost[j][j + 1]  = (s[j] == s[j + 1] ? 0 : 1);
        for (int j = 2; j < n; j++)
            for (int i = 0; i + j < n; i++)
                cost[i][i + j] = cost[i + 1][i + j - 1] + (s[i] == s[i + j] ? 0 : 1);
        vector<vector<int>> dp(n, vector<int>(k));
        for (int j = 0; j < n; j++)
            dp[j][0] = cost[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < k; j++) {
                int m = 100;
                for (int t = 0; t < i; t++) {
                    m = min(m, dp[t][j - 1] + cost[t + 1][i]);
                }
                dp[i][j] = m;
            }
        }
        return dp[n - 1][k - 1];
    }
};

int main() {
    assert(Solution().palindromePartition("aabbc", 3) == 0);
}
