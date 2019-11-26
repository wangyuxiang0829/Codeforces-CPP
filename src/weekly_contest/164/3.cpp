#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        sort(products.begin(), products.end());
        for (int i = 0; i < searchWord.size(); i++) {
            for (auto &s : products) {
                if (s.size() > i && s[i] == searchWord[i]) {
                    if (result[i].size() < 3)
                        result[i].push_back(s);
                }
                else
                    s = string();
            }
        }
        return result;
    }
};

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    auto result = Solution().suggestedProducts(products, "mouse");
    for (auto i : result) {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
}
