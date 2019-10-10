#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int match = 0, min = 0, start = 0, m = s.size(), n = t.size();
        unordered_map<char, int> map;
        unordered_map<char, int> count;
        for (auto c : t)
            map[c]++;
        for (int i = 0, j = 0; j < m; ++j) {
            if (map.find(s[j]) != map.end() && ++count[s[j]] == map[s[j]]) match++;
            while (match == map.size()) {
                if (j - i + 1 < min || min == 0) {
                    min = j - i + 1;
                    start = i;
                }
                if (map.find(s[i]) != map.end() && count[s[i]]-- == map[s[i]]) match--;
                i++;
            }
        }
        return s.substr(start, min);
    }
};

int main() {
    cout << Solution().minWindow("aa", "aa") << endl;
}
