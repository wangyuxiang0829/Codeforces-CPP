#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < coordinates.size(); ++i) {
                if (coordinates[i][0] != coordinates[0][0]) return false;
            }
        }
        auto k = ((double)coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
        for (int i = 2; i < coordinates.size(); ++i) {
            const auto &cur = coordinates[i];
            const auto &pre = coordinates[i - 1];
            if (pre[0] == cur[0] || ((double)pre[1] - cur[1]) / (pre[0] - cur[0]) != k) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> coordinates = {
        {-4, -3},
        {1, 0},
        {3, -1},
        {0, -1},
        {-5, 2},
    };
    assert(Solution().checkStraightLine(coordinates) == false);
}
