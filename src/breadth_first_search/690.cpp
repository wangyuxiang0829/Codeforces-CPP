#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        vector<pair<int, vector<int>>> G(2000);
        for (auto e : employees) {
            for_each(e->subordinates.begin(), e->subordinates.end(), [](int &i) {i--;});
            G[e->id - 1] = make_pair(e->importance, e->subordinates);
        }
        int result = 0;
        queue<int> q;
        q.push(id - 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            auto [val, adj] = G[u];
            result += val;
            for (auto v : adj)
                q.push(v);
        }
        return result;
    }
};

int main() {
    Employee e1 = {1, 5, {2, 3}};
    Employee e2 = {2, 3, {}};
    Employee e3 = {3, 3, {}};
    vector<Employee *> employees = {&e1, &e2, &e3};
    assert(Solution().getImportance(employees, 1) == 11);
}
