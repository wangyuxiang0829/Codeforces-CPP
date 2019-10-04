#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int Find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = Find(parent[v]);
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, const vector<vector<int>> &pairs) {
        int n = s.size();
        DSU dsu(n);
        for (auto &pair : pairs)
            dsu.Union(pair[0], pair[1]);
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i)
            components[dsu.Find(i)].push_back(i);
        for (auto &p : components) {
            string c;
            for (auto i : p.second)
                c += s[i];
            sort(c.begin(), c.end());
            int j = 0;
            for (auto i : p.second)
                s[i] = c[j++];
        }
        return s;
    }
};

int main() {
    cout << Solution().smallestStringWithSwaps("dcab", {{0, 3}, {1, 2}}) << endl;
    cout << Solution().smallestStringWithSwaps("dcab", {{0, 3}, {1, 2}, {0, 2}}) << endl;
    cout << Solution().smallestStringWithSwaps("cba",  {{0, 1}, {1, 2}}) << endl;
}
