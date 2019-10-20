#include <stack>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                sc.push(c);
            else if (c == ')') {
                if (sc.empty() || sc.top() != '(')
                    return false;
                sc.pop();
            }
            else if (c == '}') {
                if (sc.empty() || sc.top() != '{')
                    return false;
                sc.pop();
            }
            else if (c == ']') {
                if (sc.empty() || sc.top() != '[')
                    return false;
                sc.pop();
            }
        }
        return sc.empty();
    }
};

int main() {
    assert(Solution().isValid("()") == true);
}
