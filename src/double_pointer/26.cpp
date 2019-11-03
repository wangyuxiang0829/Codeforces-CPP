#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int i = 0, j = 1;
        while (j < nums.size()) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution().removeDuplicates(nums);
    for (auto i : nums)
        cout << i << endl;
}
