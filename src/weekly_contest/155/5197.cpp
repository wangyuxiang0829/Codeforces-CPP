#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int minimum = ~(1 << 31);
        for (int i = 0; i < arr.size() - 1; ++i)
            minimum = min(arr[i + 1] - arr[i], minimum);
        for (int i = 0; i < arr.size() - 1; ++i)
            if (arr[i + 1] - arr[i] == minimum)
                result.push_back({arr[i], arr[i + 1]});
        return result;
    }
};

int main() {
    auto result = Solution().minimumAbsDifference({4, 2, 1, 3});
    for (const auto &pair : result) {
        for (auto i : pair) cout << i << " ";
        std::cout << std::endl;
    }
}

