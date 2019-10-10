#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int match = 0, min = 0, start = 0, m = s.size(), n = t.size();
        unordered_map<char, int> count;
        for (auto c : t)
            count[c]++;
        for (int i = 0, j = 0; j < m; ++j) {
            if (count.find(s[j]) != count.end() && count[s[j]]-- > 0) match++;
            while (match == n) {
                if (j - i + 1 < min || min == 0) {
                    min = j - i + 1;
                    start = i;
                }
                if (count.find(s[i]) != count.end() && ++count[s[i]] > 0) match--;
                i++;
            }
        }
        return s.substr(start, min);
    }
};

int main() {
    cout << Solution().minWindow("aa", "aa") << endl;
}
