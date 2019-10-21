#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
        unordered_set<string> not_sub;
        for (const auto &s : folder) {
            auto iter = find(s.cbegin() + 1, s.cend(), '/');
            bool flag = true;
            while(iter != s.cend()) {
                string c(s.cbegin(), iter);
                if (not_sub.find(c) != not_sub.end()) {
                    flag = false;
                    break;
                }
                iter = find(iter + 1, s.end(), '/');
            }
            if (flag) not_sub.insert(s);
        }
        return vector<string>(not_sub.begin(), not_sub.end());
    }
};

int main() {
    vector<string> folder = {
        "/a",
        "/a/b",
        "/c/d",
        "/c/d/e",
        "/c/f"
    };
    for (auto s : Solution().removeSubfolders(folder))
        cout << s << endl;
}
