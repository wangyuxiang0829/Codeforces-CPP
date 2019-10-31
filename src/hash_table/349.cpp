#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> t(nums2.begin(), nums2.end());
        if (s.size() < t.size()) s.swap(t);
        vector<int> result;
        for (auto i : t) {
            if (s.find(i) != s.end())
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto i : Solution().intersection(nums1, nums2))
        cout << i << endl;
}
