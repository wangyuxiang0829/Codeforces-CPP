#include <vector>
#include <bitset>
#include <iostream>
#define Node(n) n - 1
//constexpr int Node(int n) {return n - 1;}
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        vector<vector<int>> G(N);
        for (const auto &e : paths) {
            G[Node(e[0])].push_back(Node(e[1]));
            G[Node(e[1])].push_back(Node(e[0]));
        }
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            bitset<5> flower;
            for (auto v : G[i])
                flower.set(result[v]);
            for (int j = 1; j <= 4; j++) {
                if (!flower[j]) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
    for (auto i : Solution().gardenNoAdj(3, paths))
        cout << i << endl;
}
