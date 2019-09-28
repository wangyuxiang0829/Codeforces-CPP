class DSU {
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> size;

public:
    DSU() = default;

    void Union(int u, int v) {
        if (parent.find(u) == parent.end()) insert(u);
        if (parent.find(v) == parent.end()) insert(v);
        int root_i = root(u);
        int root_j = root(v);
        if (root_i == root_j) return;
        if (size[root_i] < size[root_j]) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
        }
        else {
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    int disjoin_set_num() {
        std::unordered_set<int> set;
        for (auto &pair : parent) {
            set.insert(root(pair.first));
        }
        return set.size();
    }

    void insert(int u) {
        if (parent.find(u) != parent.end()) return;
        parent[u] = u;
        size[u] = 1;
    }

private:
    int root(int u) {
        if (parent[u] == u) return u;
        return root(parent[u]);
    }
};

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        DSU dsu;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int vertex = i * n + j;
                    dsu.insert(vertex);
                    if (j + 1 < n && grid[i][j + 1] == '1') 
                        dsu.Union(vertex, vertex + 1);
                    if (i + 1 < m && grid[i + 1][j] == '1')
                        dsu.Union(vertex, vertex + n);
                }
            }
        }
        return dsu.disjoin_set_num();
    }
};
