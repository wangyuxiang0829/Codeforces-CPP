#include <deque>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> sortItems(int, int, vector<int>&, vector<vector<int>>&);
private:
    deque<int> topological_order;
    unordered_set<int> not_finished;
    unordered_set<int> searched;

    template<typename T>
    bool dfs(int u, T &graph) {
        not_finished.insert(u);
        for (auto v : graph[u]) {
            if (not_finished.find(v) != not_finished.end()) return false;
            if (searched.find(v) == searched.end()) {
                if (!dfs(v, graph)) return false;
            }
        }
        not_finished.erase(u);
        searched.insert(u);
        topological_order.push_front(u);
        return true;
    }

    template<typename T>
    bool topological_sort(T &graph) {
        for (int i = 0; i < graph.size(); ++i) {
            if (searched.find(i) == searched.end()) {
                if (!dfs(i, graph)) return false;
            }
        }
        return true;
    }

    void refresh() {
        topological_order.clear();
        not_finished.clear();
        searched.clear();
    }
};

using um = unordered_map<int, vector<int>>;
template<> bool Solution::topological_sort<um>(um &graph) {
    for (auto &p : graph) {
        if (searched.find(p.first) == searched.end()) {
            if (!dfs(p.first, graph)) return false;
        }
    }
    return true;
}

vector<int> Solution::sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i)
        for (auto e : beforeItems[i])
            graph[e].push_back(i);
    vector<vector<int>> groups(m);
    for (int i = 0; i < n; ++i) {
        if (group[i] == -1) {
            groups.push_back({i});
            group[i] = m++;
        }
        else
            groups[group[i]].push_back(i);
    }
    vector<vector<int>> group_graph(m);
    vector<unordered_map<int, vector<int>>> inner_group_graph(m);
    for (int i = 0; i < m; ++i) {
        for (auto u : groups[i]) {
            if (inner_group_graph[i].find(u) == inner_group_graph[i].end())
                inner_group_graph[i].insert({u, {}});
            for (auto v : graph[u]) {
                if (group[v] != i)
                    group_graph[i].push_back(group[v]);
                else
                    inner_group_graph[i][u].push_back(v);
            }
        }
    }
    if (!topological_sort(group_graph)) return {};
    vector<int> result;
    auto group_topological_order(topological_order);
    for (auto i : group_topological_order) {
        refresh();
        if (!topological_sort(inner_group_graph[i])) return {};
        for (auto u : topological_order)
            result.push_back(u);
    }
    return result;
}

int main() {
    vector<int> group = {2, 0, -1, 3, 0};
    vector<vector<int>> beforeItems = {
        {2, 1, 3},
        {2, 4},
        {},
        {},
        {}
    };
    for (auto i : Solution().sortItems(5, 5, group, beforeItems))
        cout << i << endl;
}
