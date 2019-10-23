#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (const auto &s : folder) {
            if (result.empty() || s.find(result.back() + '/') != 0)
                result.push_back(s);
        }
        return result;
    }
};

int main() {
    vector<string> folder = {"/c/f", "/a/b", "/c/d", "/c/d/e", "/a"};
    for (auto s : Solution().removeSubfolders(folder))
        cout << s << endl;
}
