#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        vector<int> result(n);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; j += result[j]) {
                if (T[j] > T[i]) {
                    result[i] = j - i;
                    break;
                }
                else if (result[j] == 0) {
                    result[i] = 0;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    for (auto i : Solution().dailyTemperatures(T))
        cout << i << endl;
}
