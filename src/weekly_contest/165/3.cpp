#include <vector>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int result = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int k = 1; k < min(m, n); k++) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    bool flag = true;
                    for (int t = i; t < i + k && flag; t++) {
                        for (int s = j; s < j + k; s++) {
                            if (!matrix[t][s]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) result++;
                }
            }
        }
        return result;
    }
};
