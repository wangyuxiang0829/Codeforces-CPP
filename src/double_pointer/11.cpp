#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(const vector<int> &height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};

int main() {
    cout << Solution().maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
}
