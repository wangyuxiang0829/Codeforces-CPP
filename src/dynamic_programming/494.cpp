#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&](int num) { sum += num; });
        if (sum < S || ((sum + S) & 1) != 0) return 0;
        int V = (sum + S) / 2;
        vector<int> dp(V + 1);
        dp[0] = 1;
        for (auto num : nums) {
            int i = V;
            while (i >= num) {
                dp[i] = dp[i] + dp[i - num];
                i--;
            }
        }
        return dp[V];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    assert(Solution().findTargetSumWays(nums, 3) == 5);
}
