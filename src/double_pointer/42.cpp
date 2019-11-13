#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.size() < 3) return 0;
        int result = 0;
        for (int left = 1, right = height.size() - 2,
                max_left = height[left - 1], max_right = height[right + 1];
                left <= right;) {
            if (height[left - 1] < height[right + 1]) {
                if (height[left] < max_left)
                    result += max_left - height[left];
                else
                    max_left = height[left];
                left++;
            }
            else {
                if (height[right] < max_right)
                    result += max_right - height[right];
                else
                    max_right = height[right];
                right--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(Solution().trap(height) == 6);
}
