#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxEqualFreq(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, int> count, frequ;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            auto times = ++count[*iter];
            if (times != 1 && --frequ[times - 1] == 0)
                frequ.erase(times - 1);
            frequ[times]++;
            if (frequ.size() == 1) {
                auto p = frequ.begin();
                if (p->first == 1 || p->second == 1)
                    ans = max(ans, p->first * p->second);
            }
            else if (frequ.size() == 2) {
                auto p = frequ.begin(), q = p++;
                if (p->first > q->first) swap(p, q);
                if ((p->second == 1 && p->first == 1) || (q->second == 1 && q->first == p->first + 1))
                    ans = max(ans, p->first * p->second + q->first * q->second);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 5, 3, 3, 5};
    cout << Solution().maxEqualFreq(nums) << endl;
}
