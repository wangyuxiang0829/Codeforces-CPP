#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(const vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (auto num : nums)
            count[num]++;
        using value_t = pair<int, int>;
        vector<value_t> container(count.begin(), count.end());
        sort(container.begin(), container.end(), [](value_t v1, value_t v2) {
                return v1.second > v2.second;});
        auto iter = container.begin();
        vector<int> result;
        while (k--) {
            result.push_back(iter->first);
            iter++;
        }
        return result;
    }
};

int main() {
    for (auto i : Solution().topKFrequent({1, 1, 1, 2, 2, 3}, 2))
        cout << i << endl;
}
