#include <string>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int m = A.size(), n = B.size(), c = 0;
        if (m <= 1 || m != n) return false;
        vector<int> v;
        int map[26] = {0};
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (int m = ++map[A[i] - 'a']; m >= 2)
                flag = true;
            if (A[i] != B[i]) {
                c++;
                if (c > 2) return false;
                v.push_back(i);
            }
        }
        if (c == 1) return false;
        else if (c == 0) return flag;
        else return A[v[0]] == B[v[1]] && A[v[1]] == B[v[0]];
    }
};

int main() {
    assert(Solution().buddyStrings("aa", "aa") == true);
}
