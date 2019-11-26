#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candinates, int target) {
        sort(candinates.begin(), candinates.end());
        backtracking(candinates, 0, target, 0);
        return result;
    }
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &candinates, const int i, const int target, const int curSum) {
        if (curSum == target) result.push_back(path);
        else if (curSum > target) return;
        else {
            for (int j = i; j < candinates.size(); j++) {
                path.push_back(candinates[j]);
                backtracking(candinates, j, target, curSum + candinates[j]);
                path.pop_back();
            }
        }
    }
};

int main() {
    vector<int> candinates = {2, 3, 5};
    for (auto i : Solution().combinationSum(candinates, 8)) {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
}
