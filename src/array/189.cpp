#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
private:
    void reverse(vector<int> &nums, int start, int end) {
        if (start >= end) return;
        swap(nums[start], nums[end]);
        reverse(nums, start + 1, end - 1);
    }

    void swap(int &i, int &j) {
        int t = i;
        i = j;
        j = t;
    }
};

ostream &operator<<(ostream &os, const vector<int> &nums) {
    for (auto i : nums)
        os << i << ' ';
    return os;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(nums, 3);
    cout << nums << endl;
}
