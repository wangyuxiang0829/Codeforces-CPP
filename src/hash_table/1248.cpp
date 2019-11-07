#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        int result = 0, sum = 0;
        for (auto num : nums) {
            if (num & 1 != 0)
                sum += 1;
            count[sum]++;
            if (auto n = count.find(sum - k); n != count.end())
                result += n->second;
            if (sum - k == 0)
                result += 1;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    assert(Solution().numberOfSubarrays(nums, 3) == 2);
}
