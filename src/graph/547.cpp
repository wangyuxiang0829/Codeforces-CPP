#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
    std::unordered_set<int> searched;

private:
    void DFS(int u, const std::vector<std::vector<int>> &graph) {
        searched.insert(u);
        for (int v = 0; v < graph.size(); ++v) {
            if (graph[u][v] == 1 && searched.find(v) == searched.end())
                DFS(v, graph);
        }
    }

public:
    int findCircleNum(std::vector<std::vector<int>> &M) {
        int result = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (searched.find(i) == searched.end()) {
                DFS(i, M);
                result++;
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    assert(Solution().findCircleNum(graph) == 2);
    return 0;
}
