#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n);
        return answer;
    }
private:
    vector<vector<string>> answer;
    vector<string> result;
    unordered_set<int> columns;
    unordered_set<int> slashes;
    unordered_set<int> back_slashes;

    void dfs(const int i, const int n) {
        if (i >= n) {
            answer.push_back(result);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (columns.find(j) == columns.end()
                    && slashes.find(i + j) == slashes.end()
                    && back_slashes.find(i - j) == back_slashes.end()) {
                columns.insert(j);
                slashes.insert(i + j);
                back_slashes.insert(i - j);
                string s(n, '.');
                s[j] = 'Q';
                result.push_back(s);
                dfs(i + 1, n);
                columns.erase(j);
                slashes.erase(i + j);
                back_slashes.erase(i - j);
                result.pop_back();
            }
        }
    }
};

int main() {
    auto queues = Solution().solveNQueens(4);
    for (auto vs : queues) {
        for (auto s : vs) {
            cout << s << endl;
        }
        cout << endl;
    }
}
