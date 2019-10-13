#include <string>
#include <iostream>
#include <deque>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        deque<char> stack;
        int count = -1;
        for (auto c : s) {
            if (stack.empty()) {
                count++;
                stack.push_back(c);
            }
            else if (stack.back() != c) stack.pop_back();
            else stack.push_back(c);
        }
        return count + 1;
    }
};

int main() {
    cout << Solution().balancedStringSplit("RLRRLLRLRL") << endl;
}
