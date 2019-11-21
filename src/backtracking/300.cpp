#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(n, -1));
        return backtracking(nums, -1, 0, memo);
    }
private:
    int backtracking(const vector<int> &nums, int prev, int cur, vector<vector<int>> &memo) {
        if (cur >= nums.size()) return 0;
        if (memo[prev + 1][cur] >= 0)
            return memo[prev + 1][cur];
        int taken = 0;
        if (prev < 0 || nums[cur] > nums[prev])
            taken = 1 + backtracking(nums, cur, cur + 1, memo);
        int nottaken = backtracking(nums, prev, cur + 1, memo);
        memo[prev + 1][cur] = max(taken, nottaken);
        return memo[prev + 1][cur];
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(Solution().lengthOfLIS(nums) == 4);
}
