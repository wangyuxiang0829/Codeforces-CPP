#include <vector>
#include <iostream>
#include <functional>
using namespace std;
class CustomFunction {
public:
    int f(int x, int y);
};
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        using namespace placeholders;
        auto f = bind(&CustomFunction::f, &customfunction, _1, _2);
        vector<vector<int>> result;
        for (int x = 1; x <= z; ++x) {
            int l = 1, r = z;
            while (l <= r) {
                int y = (l + r) / 2;
                if (int v = f(x, y); v < z) l = y + 1;
                else if (v > z) r = y - 1;
                else break;
            }
            if (l <= r) result.push_back({x, (l + r) / 2});
        }
        return result;
    }
};

ostream &operator<<(ostream &os, const vector<vector<int>> &pairs) {
    for (auto pair : pairs)
        os << pair[0] << ',' << pair[1] << ' ';
    return os;
}

int CustomFunction::f(int x, int y) {
    return x + y;
}

int main() {
    CustomFunction f;
    cout << Solution().findSolution(f, 5) << endl;
}
