#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || p.empty() || s.size() < p.size()) return {};
        vector<int> result, map(26);
        int matches = 0, len_s = s.size(), len_p = p.size();
        for (auto c : p) map[c - 'a']++;
        for (int l = 0, r = 0; r < len_s; ++r) {
            if (--map[s[r] - 'a'] >= 0) matches++;
            if (r - l + 1 > len_p) {
                if (++map[s[l] - 'a'] > 0) matches--;
                l++;
            }
            if (matches == len_p) result.push_back(l);
        }
        return result;
    }
};

int main() {
    for (auto c : Solution().findAnagrams("cbaebabacd", "abc"))
        cout << c << endl;
}
