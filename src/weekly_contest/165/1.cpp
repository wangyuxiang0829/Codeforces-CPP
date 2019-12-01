#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        if (moves.size() < 5) return "Pending";
        vector<vector<int>> map(3, vector<int>(3));
        int k = 0;
        for (auto &m : moves) {
            int i = m[0], j = m[1];
            if (k & 1)
                map[i][j] = 2;
            else
                map[i][j] = 1;
            k++;
        }
        if (map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
            if (map[0][0] == 1)
                return "A";
            else if (map[0][0] == 2)
                return "B";
        }
        if (map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
            if (map[1][1] == 1)
                return "A";
            else if (map[1][1] == 2)
                return "B";
        }
        vector<int> row1(3), col1(3), row2(3), col2(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i][j] == 1) {
                    row1[i]++;
                    col1[j]++;
                }
                else if (map[i][j] == 2) {
                    row2[i]++;
                    col2[j]++;
                }
            }
        }
        for (auto c : row1)
            if (c >= 3)
                return "A";
        for (auto c : col1)
            if (c >= 3)
                return "A";
        for (auto c : row2)
            if (c >= 3)
                return "B";
        for (auto c : col2)
            if (c >= 3)
                return "B";
        if (moves.size() < 9)
            return "Pending";
        else
            return "Draw";
    }
};

int main() {
    vector<vector<int>> moves = {{0, 0}, {1, 1}};
    cout << Solution().tictactoe(moves) << endl;
}
