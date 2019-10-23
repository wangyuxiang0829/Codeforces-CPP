#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        const auto dx = coordinates[0][0] - coordinates[1][0];
        const auto dy = coordinates[0][1] - coordinates[1][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            auto dix = coordinates[0][0] - coordinates[i][0];
            auto diy = coordinates[0][1] - coordinates[i][1];
            if (dx * diy != dy * dix) return false;
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
