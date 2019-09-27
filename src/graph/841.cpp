#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
    std::unordered_set<int> searched;

private:
    void DFS(const std::vector<std::vector<int>> &graph, int u) {
        searched.insert(u);
        for (auto v : graph[u]) {
            if (searched.find(v) == searched.end()) {
                DFS(graph, v);
            }
        }
    }

public:
    bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
        DFS(rooms, 0);
        return searched.size() == rooms.size();
    }
};

int main() {
    std::vector<std::vector<int>> graph = {
        {1},
        {2},
        {3},
        {}
    };
    assert(Solution().canVisitAllRooms(graph) == true);
    return 0;
}

