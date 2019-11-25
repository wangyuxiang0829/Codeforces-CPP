#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int minTime = 0;
        int p = points[0][0], q = points[0][1];
        for (int k = 1; k < points.size(); k++) {
            int i = points[k][0], j = points[k][1];
            if (j == q || i == p )
                minTime += abs((j - q) + (i - p));
            else if (j - q == i - p)
                minTime += abs(j - q);
            else
                minTime += max(abs(i - p), abs(j - q));
            p = i, q = j;
        }
        return minTime;
    }
};

int main() {
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    assert(Solution().minTimeToVisitAllPoints(points) == 7);
}
