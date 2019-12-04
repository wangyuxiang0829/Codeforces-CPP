#include <vector>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> t(n, vector<int>(m, -1));
        v = t;
        return isMatch(s, p, n - 1, m - 1);
    }
private:
    vector<vector<int>> v;
    bool isMatch(const string &s, const string &p, int i, int j) {
        if (i < 0 && j < 0) return true;
        else if (j < 0) return false;
        else if (i < 0) {
            for (int k = j; k >= 0; k--) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (v[i][j] != -1) return v[i][j];
        char c = p[j];
        bool match = false;
        if (c == '?')
            match = isMatch(s, p, i - 1, j - 1);
        else if (c == '*')
            match = isMatch(s, p, i, j - 1) || isMatch(s, p, i - 1, j);
        else
            match = s[i] == p[j] && isMatch(s, p, i - 1, j - 1);
        v[i][j] = match;
        return match;
    }
};
int main() {
    assert(Solution().isMatch("abceb", "*a*b") == true);
}
