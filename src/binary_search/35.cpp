#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums, 0, nums.size(), target);
    }
private:
    int lower_bound(const vector<int> &nums, int l, int r, int v) {
        if (l == r) return l;
        int m = (l + r) / 2;
        if (nums[m] < v) return lower_bound(nums, m + 1, r, v);
        else return lower_bound(nums, l, m, v);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    assert(Solution().searchInsert(nums, 5) == 2);
}
