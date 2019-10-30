#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end   = upper_bound(nums.begin(), nums.end(), target);
        if (begin == end) return {-1, -1};
        return {(int)(begin - nums.begin()), (int)(end - nums.begin() - 1)};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    for (auto i : Solution().searchRange(nums, 8))
        cout << i << endl;
}
