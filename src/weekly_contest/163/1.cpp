#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        return helper(move(grid), 0, k);
    }
private:
    vector<vector<int>> helper(vector<vector<int>> grid, int i, int k) {
        if (i >= k) return grid;
        int n = grid.size(), m = grid[0].size();
        vector<int> first(n);
        for (int i = n - 1; i > 0; i--) {
            first[i] = grid[i][0];
            grid[i][0] = grid[i - 1][m - 1];
        }
        first[0] = grid[0][0];
        grid[0][0] = grid[n - 1][m - 1];
        for (int i = 0; i < n; i++)
            for (int j = m - 1; j > 0; j--)
                grid[i][j] = grid[i][j - 1];
        if (m > 1) {
            for (int i = 0; i < n; i++)
                grid[i][1] = first[i];
        }
        else
            grid[0][0] = first[n - 1];
        return helper(move(grid), i + 1, k);
    }
};

int main() {
    vector<vector<int>> grid = {{1},{2},{3},{4},{7},{6},{5}};
    for (auto i : Solution().shiftGrid(grid, 23)) {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
}
