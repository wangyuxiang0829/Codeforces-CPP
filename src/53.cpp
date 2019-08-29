#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int dp = nums[0];
        int m = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (dp < 0)
            {
                dp = nums[i];
            }
            else
            {
                dp = dp + nums[i];
            }
            m = max(m, dp);
        }
        return m;
    }
};
