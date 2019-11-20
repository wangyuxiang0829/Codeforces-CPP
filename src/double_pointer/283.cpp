#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        for (int i = -1, j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
    }
};

ostream &operator<<(ostream &os, const vector<int> &nums) {
    for (auto i :nums)
        os << i << ' ';
    return os;
}

int main() {
    vector nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    cout << nums << endl;
}
