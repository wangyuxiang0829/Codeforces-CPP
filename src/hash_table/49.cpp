#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto s : strs) {
            string c = s;
            sort(s.begin(), s.end());
            map[s].push_back(c);
        }
        vector<vector<string>> result;
        for (auto p : map) {
            result.push_back(p.second);
        }
        return result;
    }
};

int main() {
    vector<string> strs = {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat"
    };
    auto result = Solution().groupAnagrams(strs);
    for (auto v : result) {
        for (auto s : v) {
            cout << s << ", ";
        }
        cout << endl;
    }
}
