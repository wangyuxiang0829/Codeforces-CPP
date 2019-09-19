#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;
        int dp[n][n] = {};
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            int length = triangle[i].size();
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][length - 1] = dp[i - 1][length - 2] + triangle[i][length - 1];
            for (int j = 1; j < length - 1; ++j) {
                dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int min = dp[n - 1][0];
        for (int j = 1; j < n; ++j) {
            if (dp[n - 1][j] < min)
                min = dp[n - 1][j];
        }
        return min;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    assert(s.minimumTotal(v) == 11);
    return 0;
}

