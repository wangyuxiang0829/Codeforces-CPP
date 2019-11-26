#include <set>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candinates, int target) {
        backtracking(candinates, target, vector<int>(), 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
private:
    set<vector<int>> result;

    void backtracking(const vector<int> &candinates, const int target, vector<int> path, const int curSum) {
        if (curSum == target) {
            sort(path.begin(), path.end());
            result.insert(path);
        }
        else if (curSum > target) return;
        else {
            for (auto i : candinates) {
                path.push_back(i);
                backtracking(candinates, target, path, curSum + i);
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
