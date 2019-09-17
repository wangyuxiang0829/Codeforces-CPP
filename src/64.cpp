#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n] = {};
        for (int j = 0, sum = 0; j < n; ++j) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }
        for (int i = 0, sum = 0; i < m; ++i) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    Solution s;
    assert(s.minPathSum(grid) == 7);
    return 0;
}
