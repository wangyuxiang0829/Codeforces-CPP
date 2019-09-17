#include <vector>
#include <cassert>

class Solution {
public:
    std::size_t uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        std::size_t dp[m][n] = {};
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            }
            else {
                while (j < n) {
                    dp[0][j++] = 0;
                }
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            }
            else {
                while (i < m) {
                    dp[i++][0] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    assert(s.uniquePathsWithObstacles(grid) == 2);
    return 0;
}

