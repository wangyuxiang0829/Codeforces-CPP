#include <stack>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for (auto c : s) {
            if (c == '(')
                st.push(string());
            else if (c == ')') {
                string t = st.top();
                st.pop();
                reverse(t.begin(), t.end());
                if (st.empty()) st.push(string());
                st.top().append(move(t));
            }
            else {
                if (st.empty())
                    st.push(string(1, c));
                else
                    st.top().push_back(c);
            }
        }
        return st.top();
    }
};

int main() {
    cout << Solution().reverseParentheses("(u(love)i)") << endl;
}
