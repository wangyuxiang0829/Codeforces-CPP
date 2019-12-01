#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> numOfBurgers(int m, int n) {
        int t = m - 2 * n;
        if (t < 0 || t % 2 != 0)
            return vector<int>();
        int x = t / 2;
        int y = n - x;
        if (y < 0) return vector<int>();
        return {x, y};
    }
};
int main() {
    auto result = Solution().numOfBurgers(16, 7);
    cout << result[0] << ' ' << result[1] << endl;
}
