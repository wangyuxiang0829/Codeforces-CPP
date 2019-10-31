#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2, maximum = m;
            if (m - 1 >= 0 && nums[m - 1] > nums[m])
                maximum = m - 1;
            if (m + 1 < nums.size() && nums[m + 1] > nums[maximum])
                maximum = m + 1;
            if (maximum == m) return m;
            else if (maximum < m) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int index = Solution().findPeakElement(nums);
    assert(index == 1 || index == 5);
}
