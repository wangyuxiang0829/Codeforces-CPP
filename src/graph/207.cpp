#include <vector>
#include <unordered_set>

class Solution {
    std::unordered_set<int> unfinished;
    std::unordered_set<int> searched;
private:
    bool dfs(int i, std::vector<std::vector<int>> &prerequisites) {
        searched.insert(i);
        unfinished.insert(i);
        for (auto &edge : prerequisites) {
            if (edge[0] == i) {
                if (unfinished.find(edge[1]) != unfinished.end()) return false;
                if (searched.find(edge[1]) == searched.end())
                    if (!dfs(edge[1], prerequisites)) return false;
            }
        }
        unfinished.erase(i);
        return true;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            if (searched.find(i) == searched.end()) {
                if (!dfs(i, prerequisites)) return false;
            }
        }
        return true;
    }
};

