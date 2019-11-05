#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(string T, string P) {
        if (P.empty()) return 0;
        if (T.empty()) return -1;
        int n = T.length(), m = P.length(), q = 0;
        auto pi = compute_prefix_function(P);
        for (int i = 0; i < n; ++i) {
            while (q > 0 && P[q] != T[i])
                q = pi[q - 1];
            if (P[q] == T[i])
                q = q + 1;
            if (q == m)
                return i - m + 1;
        }
        return -1;
    }
private:
    vector<int> compute_prefix_function(const string &P) {
        int m = P.length(), k = 0;
        vector<int> pi(m);
        for (int q = 1; q < m; q++) {
            while (k > 0 && P[k] != P[q])
                k = pi[k - 1];
            if (P[k] == P[q])
                k = k + 1;
            pi[q] = k;
        }
        return pi;
    }
};

int main() {
    assert(Solution().strStr("a", "a") == 0);
}
