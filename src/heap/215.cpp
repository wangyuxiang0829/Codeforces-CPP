#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <functional>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> q(less<int>(), move(nums));
        k--;
        while (k--) {
            q.pop();
        }
        return q.top();
    }
};

int main() {
    vector<int> nums1{3, 2, 1, 5, 6, 4};
    vector<int> nums2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << Solution().findKthLargest(nums1, 2) << endl;
    cout << Solution().findKthLargest(nums2, 4) << endl;
}
