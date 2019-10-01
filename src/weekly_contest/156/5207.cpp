#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        for (int i = 0, j = 0, currentCost = 0; j < s.size(); ++j) {
            currentCost += abs(s[j] - t[j]);
            while (currentCost > maxCost) {
                currentCost -= abs(s[i] - t[i]);
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};

int main() {
    cout << Solution().equalSubstring("abcd", "bcdf", 3) << endl;
    cout << Solution().equalSubstring("abcd", "cdef", 3) << endl;
    cout << Solution().equalSubstring("abcd", "acde", 0) << endl;
}
