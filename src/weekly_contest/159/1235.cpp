#include <tuple>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    using job = tuple<int, int, int>;
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<job> jobs;
        for (int i = 0; i < startTime.size(); ++i) jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(endTime.begin(), endTime.end());
        endTime.resize(unique(endTime.begin(), endTime.end()) - endTime.begin());
        sort(jobs.begin(), jobs.end(), [](const job &j1, const job &j2) { return get<1>(j1) < get<1>(j2); });
        vector<int> dp(endTime.size() + 1, 0);
        for (auto j : jobs) {
            int start = get<0>(j), end = get<1>(j);
            start     = upper_bound(endTime.begin(), endTime.end(), start) - endTime.begin();
            end       = lower_bound(endTime.begin(), endTime.end(), end) - endTime.begin() + 1;
            dp[end]   = max({dp[end], dp[end - 1], dp[start] + get<2>(j)});
        }
        return dp.back();
    }
};

int main() {
    vector<int> s = {1, 2, 3, 4, 6};
    vector<int> e = {3, 5, 10, 6, 9};
    vector<int> p = {20, 20, 100, 70, 60};
    assert(Solution().jobScheduling(s, e, p) == 150);
}
