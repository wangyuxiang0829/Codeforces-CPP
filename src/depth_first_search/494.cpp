#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        dfs(0, 0, nums, S);
        return result;
    }
private:
    int result = 0;
    void dfs(int sum, int i, const vector<int> &nums, int S) {
        if (i >= nums.size()) {
            if (sum == S)
                result++;
            return;
        }
        dfs(sum + nums[i], i + 1, nums, S);
        dfs(sum - nums[i], i + 1, nums, S);
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    assert(Solution().findTargetSumWays(nums, 3) == 5);
}
