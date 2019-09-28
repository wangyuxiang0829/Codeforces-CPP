class DSU {
    vector<int> parent;
    
public:
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    
    void merge(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        parent[root_i] = root_j;
    }
    
private:
    int find(int i) {
        if (parent[i] == i) return i;
        return find(parent[i]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        DSU disjoint_set(edges.size() + 1);
        for (auto &edge : edges) {
            if (disjoint_set.connected(edge[0], edge[1]))
                return edge;
            disjoint_set.merge(edge[0], edge[1]);
        }
        return {};
    }
};
