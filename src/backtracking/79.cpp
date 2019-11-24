#include <vector>
#include <string>
#include <cassert>
using namespace std;
#define legal(i, j) (i >= 0 && i < n && j >= 0 && j < m)
class Solution {
public:
    using grid = vector<vector<char>>;
    bool exist(grid &board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (backtracking(board, word, i, j, 0))
                    return true;
        return false;
    }
private:
    static constexpr int dir[4][2] = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0}
    };

    bool backtracking(grid &g, const string &word, int i, int j, int c) {
        int n = g.size(), m = g[0].size();
        if (!legal(i, j) || g[i][j] != word[c]) return false;
        if (c == word.size() - 1) return true;
        g[i][j] = '\0';
        for (int d = 0; d < 4; d++)
            if (backtracking(g, word, i + dir[d][0], j + dir[d][1], c + 1))
                return true;
        g[i][j] = word[c];
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    auto board0(board), board1(board), board2(board);

    vector<vector<char>> board3 = {{'a', 'a'}};

    assert(Solution().exist(board0, "ABCCED") == true);
    assert(Solution().exist(board1, "SEE") == true);
    assert(Solution().exist(board2, "ABAB") == false);
    assert(Solution().exist(board3, "aaa") == false);
}
