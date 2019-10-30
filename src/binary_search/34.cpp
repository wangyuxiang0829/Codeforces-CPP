#include <vector>
#include <iostream>
using namespace std;

int lower_bound(const vector<int> &nums, const int v) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] < v) l = m + 1;
        else r = m;
    }
    return l;
}

int upper_bound(const vector<int> &nums, const int v) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] <= v) l = m + 1;
        else r = m;
    }
    return l;
}

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto begin = lower_bound(nums, target);
        auto end   = upper_bound(nums, target);
        if (begin == end) return {-1, -1};
        return {begin, end - 1};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    for (auto i : Solution().searchRange(nums, 8))
        cout << i << endl;
}
