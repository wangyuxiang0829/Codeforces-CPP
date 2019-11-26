#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return backtracking(s, p, s.size() - 1, p.size() - 1);
    }
private:
    bool backtracking(const string &s, const string &p, int i, int j) {
        if (i < 0) {
            if (j < 0) return true;
            if (p[j] == '*') return backtracking(s, p, i, j - 2);
            else return false;
        }
        else {
            if (j < 0) return false;
            if (p[j] == '*') {
                char c = p[j - 1];
                for (int k = i; k >= 0 && (c == '.' || s[k] == c); k--) {
                    if (backtracking(s, p, k - 1, j - 2))
                        return true;
                }
                return backtracking(s, p, i, j - 2);
            }
            else if (p[j] == '.') {
                return backtracking(s, p, i - 1, j - 1);
            }
            else {
                if (s[i] == p[j])
                    return backtracking(s, p, i - 1, j - 1);
                else
                    return false;
            }
        }
    }
};

int main() {
    assert(Solution().isMatch("aab", "c*a*b") == true);
}
