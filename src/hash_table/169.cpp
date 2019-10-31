#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        for (auto i : nums)
            count[i]++;
        int num = 0, n = nums.size() / 2;
        for (auto p : count) {
            if (p.second > n) {
                num = p.first;
                break;
            }
        }
        return num;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    assert(Solution().majorityElement(nums) == 3);
}
