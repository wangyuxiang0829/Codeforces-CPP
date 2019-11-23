#include <vector>
#include <string>
#include <cassert>
using namespace std;
#define legal(i, j) (i >= 0 && i < n && j >= 0 && j < m)
class Solution {
public:
    using grid = vector<vector<char>>;
    bool exist(grid &board, string word) {
        if (board.empty()) return false;
        int n = board.size(), m = board[0].size();
        vector<pair<int, int>> all;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    all.push_back({i, j});
        if (all.empty()) return false;
        for (auto p : all) {
            int i = p.first, j = p.second;
            board[i][j] = '\0';
            if (backtrack(board, word, i, j, 1)) {
                board[i][j] = word[0];
                return true;
            }
            board[i][j] = word[0];
        }
        return false;
    }
private:
    bool backtrack(grid &g, const string &word, int i, int j, int c) {
        if (c == word.size()) return true;
        int n = g.size(), m = g[0].size();
        for (int d = 0; d < 4; d++) {
            int _i = i + dir[d][0];
            int _j = j + dir[d][1];
            if (legal(_i, _j) && g[_i][_j] == word[c]) {
                g[_i][_j] = '\0';
                if (backtrack(g, word, _i, _j, c + 1)) {
                    g[_i][_j] = word[c];
                    return true;
                }
                g[_i][_j] = word[c];
            }
        }
        return false;
    }
    static constexpr int dir[4][2] = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0}
    };
};
int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    vector<vector<char>> b = {{'a', 'a'}};

    assert(Solution().exist(board, "ABCCED") == true);
    assert(Solution().exist(board, "SEE") == true);
    assert(Solution().exist(board, "ABAB") == false);
    assert(Solution().exist(b, "aaa") == false);
}
