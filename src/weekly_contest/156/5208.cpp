#include <unordered_map>
#include <cassert>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

enum direction {vertical, horizontal};

class status_graph {
public:
    typedef tuple<int, int, direction> vertex_t;

    auto adjacent_vertices(const vertex_t &vertex, const vector<vector<int>> &grid) {
        vector<vertex_t> adjacent_arr;
        int i = get<0>(vertex), j = get<1>(vertex), n = grid.size();
        direction k = get<2>(vertex);
        auto right = make_tuple(i, j + 1, k);
        auto down  = make_tuple(i + 1, j, k);
        if (vertex_valid(right, grid)) adjacent_arr.push_back(right);
        if (vertex_valid(down,  grid)) adjacent_arr.push_back(down);
        vertex_t whirl; bool flag = false;
        if (k == horizontal) {
            if (i + 1 < n && grid[i + 1][j] != 1 && grid[i + 1][j - 1] != 1) flag = true;
            whirl = make_tuple(i + 1, j - 1, vertical);
        }
        else {
            if (j + 1 < n && grid[i][j + 1] != 1 && grid[i - 1][j + 1] != 1) flag = true;
            whirl = make_tuple(i - 1, j + 1, horizontal);
        }
        if (flag && vertex_valid(whirl, grid)) adjacent_arr.push_back(whirl);
        return adjacent_arr;
    }
private:
    bool vertex_valid(const vertex_t &vertex, const vector<vector<int>> &grid) {
        int i = get<0>(vertex), j = get<1>(vertex), k = get<2>(vertex), n = grid.size();
        if (i >= n || j >= n) return false;
        if (k == horizontal) {
            if (grid[i][j - 1] == 1 || grid[i][j] == 1) return false;
        }
        else {
            if (grid[i - 1][j] == 1 || grid[i][j] == 1) return false;
        }
        return true;
    }
};

struct TupleHasher {
    size_t operator()(const status_graph::vertex_t &obj) const noexcept {
        return get<0>(obj) + get<1>(obj) + get<2>(obj);
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>> &grid) {
        status_graph graph;
        queue<status_graph::vertex_t> q;
        unordered_map<status_graph::vertex_t, int, TupleHasher> m;
        int n = grid.size();
        auto start = make_tuple(0, 1, horizontal);
        auto end   = make_tuple(n - 1, n - 1, horizontal);
        m[start] = 0;
        q.push(start);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : graph.adjacent_vertices(u, grid)) {
                if (m.find(v) == m.end()) {
                    m[v] = m[u] + 1;
                    q.push(v);
                    if (v == end) return m[v];
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> v = {
        {0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0}
    };
    assert(Solution().minimumMoves(v) == 11);
}

