#include <deque>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> stack;
        for (auto c : s) {
            if (!stack.empty() && c == stack.back().first) {
                if (++stack.back().second == k) stack.pop_back();
            }
            else {
                stack.push_back(make_pair(c, 1));
            }
        }
        string result;
        for (auto &p : stack) {
            while (p.second--) result += p.first;
        }
        return result;
    }
};

int main() {
    cout << Solution().removeDuplicates("deeedbbcccbdaa", 3) << endl;
}

