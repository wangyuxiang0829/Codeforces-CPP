#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                    dfs(grid, m, n, i, j);
            }
        }
        return ans;
    }
private:
    int cur = 0;
    int ans = 0;
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &grid, int m, int n, int i, int j) {
        cur += grid[i][j];
        grid[i][j] = -grid[i][j];
        ans = max(ans, cur);
        for (int k = 0; k < 4; ++k) {
            int p = i + dirs[k][0];
            int q = j + dirs[k][1];
            if (p >= 0 && p < m && q >= 0 && q < n && grid[p][q] > 0)
                dfs(grid, m, n, p, q);
        }
        cur += grid[i][j];
        grid[i][j] = -grid[i][j];
    }
};
