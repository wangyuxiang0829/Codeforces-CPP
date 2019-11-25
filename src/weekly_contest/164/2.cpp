#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && (row[i] > 1 || col[j] > 1))
                    count++;
        return count;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0}, {1, 1}};
    assert(Solution().countServers(grid) == 3);
}
