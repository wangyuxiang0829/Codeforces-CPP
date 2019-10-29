#include <vector>
#include <climits>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res, vector<int>(nums.size(), INT_MAX));
        return res;
    }
private:
    void dfs(vector<int> &nums, int i, vector<vector<int>> &res, vector<int> pre) {
        if (i >= nums.size()) res.push_back(move(pre));
        for (int j = 0; j < pre.size(); j++) {
            if (pre[j] == INT_MAX) {
                auto cur = pre;
                cur[j] = nums[i];
                dfs(nums, i + 1, res, move(cur));
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = Solution().permute(nums);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}
