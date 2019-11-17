#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

struct getSum {
    int sum = 0;
    void operator()(int i) {
        sum += i;
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        auto getsum = for_each(nums.begin(), nums.end(), getSum());
        vector<int> div1, div2;
        for (auto i : nums) {
            if (int j = i % 3; j == 1) div1.push_back(i);
            else if (j == 2) div2.push_back(i);
        }
        sort(div1.begin(), div1.end());
        sort(div2.begin(), div2.end());
        if (int sum = getsum.sum, div = sum % 3; div == 0)
            return sum;
        else if (div == 1) {
            int m = 1e4;
            if (!div1.empty())
                m = min(m, div1[0]);
            if (div2.size() > 1)
                m = min(m, div2[0] + div2[1]);
            return sum - m;
        }
        else {
            int m = 1e4;
            if (div1.size() > 1)
                m = min(m, div1[0] + div1[1]);
            if (!div2.empty())
                m = min(m, div2[0]);
            return sum - m;
        }
    }
};

int main() {
    vector<int> nums = {3, 6, 5, 1, 8};
    assert(Solution().maxSumDivThree(nums) == 18);
}
