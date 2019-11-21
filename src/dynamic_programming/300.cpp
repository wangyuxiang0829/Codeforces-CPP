#include <vector>
#include <limits>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_value = 1;
        for (int i = 1; i < n; i++) {
            int m = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] > m)
                    m = dp[j];
            }
            dp[i] = m + 1;
            max_value = max(dp[i], max_value);
        }
        return max_value;
    }
};

int main() {
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    assert(Solution().lengthOfLIS(nums) == 6);
}
longest-increasing-subsequence
