#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int subarraySum(const vector<int> &nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int sum = 0, res = 0;
        for (auto num : nums) {
            sum += num;
            if (count.find(sum - k) != count.end())
                res += count[sum - k];
            count[sum]++;
        }
        return res;
    }
};

int main() {
    assert(Solution().subarraySum({1, 1, 1}, 2) == 2);
    assert(Solution().subarraySum({1}, 0) == 0);
}
