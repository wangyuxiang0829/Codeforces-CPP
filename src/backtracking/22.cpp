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
        if (n == 0 && m == 0) {
            result.push_back(s);
            return;
        }
        if (n > 0) backtracking(n - 1, m, s + '(');
        if (n < m) backtracking(n, m - 1, s + ')');
    }
};

int main() {
    for (auto s : Solution().generateParenthesis(3))
        cout << s << endl;
}
