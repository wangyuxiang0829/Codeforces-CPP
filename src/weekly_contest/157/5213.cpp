#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int> &chips) {
        int num_even = 0, num_odd = 0;
        for (auto i : chips) {
            if (i & 1) num_odd++;
            else num_even++;
        }
        return min(num_odd, num_even);
    }
};

int main() {
    vector<int> chips = {1, 2, 3};
    cout << Solution().minCostToMoveChips(chips) << endl;
}
