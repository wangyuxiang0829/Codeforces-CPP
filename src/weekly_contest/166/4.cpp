#include <set>
#include <queue>
#include <array>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    using state = array<array<int, 3>, 3>;
    int minFlips(vector<vector<int>> &mat) {
        state target = {0}, init = {0};
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                init[i][j] = mat[i][j];
        set<state> searched;
        queue<pair<state, int>> q;
        q.push(make_pair(init, 0));
        searched.insert(init);
        while (!q.empty()) {
            auto [v, val] = q.front();
            q.pop();
            if (v == target)
                return val;
            auto adj_states = get_adj(v, m, n);
            for (auto u : adj_states) {
                if (searched.find(u) == searched.end()) {
                    searched.insert(u);
                    q.push(make_pair(u, val + 1));
                }
            }
        }
        return -1;
    }
private:
    vector<state> get_adj(const state &v, int m, int n) {
        vector<state> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                state s(v);
                reverse(s[i][j]);
                if (i - 1 >= 0)
                    reverse(s[i - 1][j]);
                if (i + 1 < m)
                    reverse(s[i + 1][j]);
                if (j - 1 >= 0)
                    reverse(s[i][j - 1]);
                if (j + 1 < n)
                    reverse(s[i][j + 1]);
                result.push_back(s);
            }
        }
        return result;
    }

    constexpr void reverse(int &i) {
        i = (i == 0 ? 1 : 0);
    }
};

int main() {
    vector<vector<int>> mat = {{0, 0}, {0, 1}};
    assert(Solution().minFlips(mat) == 3);
}
