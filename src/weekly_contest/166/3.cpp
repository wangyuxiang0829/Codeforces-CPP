#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int max = 0;
        for_each(nums.begin(), nums.end(), [&](int num) { if (num > max) max = num; });
        int l = 1, r = max, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_sum(nums, m) <= threshold)
                r = m;
            else
                l = m + 1;
            if (l == r) {
                m = l;
                break;
            }
        }
        return m;
    }
private:
    int get_sum(const vector<int> &nums, int k) {
        int sum = 0;
        for (auto num : nums) {
            sum += num / k;
            if (num % k != 0)
                sum += 1;
        }
        return sum;
    }
};
int main() {
    vector<int> nums = {1, 2, 5, 9};
    assert(Solution().smallestDivisor(nums, 6) == 5);
}
