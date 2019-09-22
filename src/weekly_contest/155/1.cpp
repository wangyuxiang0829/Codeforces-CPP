#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> result;
        auto min = std::numeric_limits<int>::max();
        for (int i = 0; i < arr.size() - 1; ++i)
            if (arr[i + 1] - arr[i] < min) min = arr[i + 1] - arr[i];
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == min) {
                result.push_back(std::vector<int>{arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> tmp{4, 2, 1, 3};
    auto result = s.minimumAbsDifference(tmp);
    for (const auto &pair : result) {
        for (auto i : pair) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

