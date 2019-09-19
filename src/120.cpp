#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] = std::min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    assert(s.minimumTotal(v) == 11);
    return 0;
}

