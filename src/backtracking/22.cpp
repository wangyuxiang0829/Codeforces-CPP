#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, n, string());
        return result;
    }
private:
    vector<string> result;

    void backtracking(int n, int m, string s) {
        if (n == 0 && m == 0)
            result.push_back(s);
        else if (n == 0)
            backtracking(0, m - 1, string(s).append(1, ')'));
        else {
            backtracking(n - 1, m, string(s).append(1, '('));
            if (n == m) return;
            backtracking(n, m - 1, s.append(1, ')'));
        }
    }
};

int main() {
    for (auto s : Solution().generateParenthesis(3))
        cout << s << endl;
}
