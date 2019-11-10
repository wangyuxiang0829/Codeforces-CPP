#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int n = arr.size(), result = arr[0];
        if (n == 1) return result;
        vector<int> l(n), r(n);
        l[0] = arr[0], r[n - 1] = arr[n - 1];
        for (int i = 1; i < n; ++i) {
            l[i] = max(l[i - 1] + arr[i], arr[i]);
            result = max(result, l[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(r[i + 1] + arr[i], arr[i]);
            result = max(result, r[i]);
        }
        for (int i = 1; i < n - 1; i++)
            result = max(result, l[i - 1] + r[i + 1]);
        return result;
    }
};

int main() {
    vector<int> arr = {1, -2, 0, 3};
    assert(Solution().maximumSum(arr) == 4);
}
