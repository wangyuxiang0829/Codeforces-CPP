#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &edge : prerequisites)
            graph[edge[1]].push_back(edge[0]);
        vector<int> flag(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (flag[i] == 0)
                if (!dfs(i, graph, flag)) return false;
        return true;
    }
private:
    bool dfs(int u, const vector<vector<int>> &graph, vector<int> &flag) {
        flag[u] = 1;
        for (auto v : graph[u]) {
            if (flag[v] == 1) return false;
            if (flag[v] == 0 && !dfs(v, graph, flag)) return false;
        }
        flag[u] = -1;
        return true;
    }
};

int main() {
    cout << Solution().canFinish(2, {{1, 0}, {0, 1}}) << endl;
}
