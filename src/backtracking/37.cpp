#include <vector>
#include <bitset>
#include <iostream>
using namespace std;
#define g(i, j) (i / 3 * 3 + j / 3)
class Solution {
public:
    bool solveSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (char c = board[i][j]; c != '.') {
                    int k = c - '0' - 1;
                    row[i][k] = 1, col[j][k] = 1;
                    grid[g(i, j)][k] = 1;
                }
            }
        }
        return backtracking(board, 0, 0);
    }
private:
    bitset<9> row[9], col[9], grid[9];

    bool backtracking(vector<vector<char>> &board, int i, int j) {
        if (i > 8) return true;
        if (board[i][j] != '.') {
            if (j == 8) return backtracking(board, i + 1, 0);
            else return backtracking(board, i, j + 1);
        }
        for (int k = 0; k < 9; k++) {
            if (!row[i][k] && !col[j][k] && !grid[g(i, j)][k]) {
                board[i][j] = k + '0' + 1;
                row[i][k] = 1, col[j][k] = 1, grid[g(i, j)][k] = 1;
                if (j == 8) {
                    if (backtracking(board, i + 1, 0))
                        return true;
                }
                else {
                    if (backtracking(board, i, j + 1))
                        return true;
                }
                board[i][j] = '.';
                row[i][k] = 0, col[j][k] = 0, grid[g(i, j)][k] = 0;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    if (Solution().solveSudoku(board)) {
        for (auto i : board) {
            for (auto j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
    else
        cout << "can't solve this problem!" << endl;
}
