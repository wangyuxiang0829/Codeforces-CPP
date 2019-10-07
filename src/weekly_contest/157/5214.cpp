#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        unordered_map<int, int> dp;
        int result = 0;
        for (auto i : arr) {
            int j = i - difference;
            if (dp.find(j) == dp.end())
                dp[i] = 1;
            else
                dp[i] = dp[j] + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << Solution().longestSubsequence(arr, 1) << endl;
}
