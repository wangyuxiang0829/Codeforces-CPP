#include <queue>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        int N = grid.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) q.emplace(i, j);
            }
        }
        if (q.size() == N * N) return -1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int m = i + dir[d][0], n = j + dir[d][1];
                if (m >= 0 && m < N && n >= 0 && n < N && !grid[m][n]) {
                    q.emplace(m, n);
                    grid[m][n] = grid[i][j] + 1;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > max) max = grid[i][j];
            }
        }
        return max - 1;
    }
private:
    static constexpr int dir[4][2] = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0},
    };
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
    };
    assert(Solution().maxDistance(grid) == -1);
}
