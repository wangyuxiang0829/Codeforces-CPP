#include <random>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, nums.size() - 1);
        int rand = dis(gen);
        while (!isMajority(nums, rand))
            rand = dis(gen);
        return nums[rand];
    }
private:
    bool isMajority(vector<int> &nums, int i) {
        int count = 0;
        for (auto j : nums)
            if (j == nums[i])
                count++;
        if (count > nums.size() / 2) return true;
        else return false;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    assert(Solution().majorityElement(nums) == 3);
}
