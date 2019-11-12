#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        int n = height.size(), result = 0;
        vector<int> start(n), end(n);
        start[0] = height[0], end.back() = height.back();
        for(int i = 1; i < n; i++)
            start[i] = max(start[i - 1], height[i]);
        for (int i = n - 2; i >= 0; i--)
            end[i] = max(end[i + 1], height[i]);
        for (int i = 1; i < n - 1; i++) {
            int h = min(start[i - 1], end[i + 1]);
            if (h > height[i])
                result += h - height[i];
        }
        return result;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(Solution().trap(height) == 6);
}
