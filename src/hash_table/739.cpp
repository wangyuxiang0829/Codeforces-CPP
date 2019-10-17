#include <vector>
#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        unordered_map<int, vector<int>::reverse_iterator> map;
        for (auto iter = T.rbegin(); iter != T.rend(); ++iter) {
            int result = 0;
            for (int i = *iter + 1; i <= 100; ++i) {
                if (map.find(i) != map.end() && (result > distance(map[i], iter) || result == 0)) {
                    result = distance(map[i], iter);
                }
            }
            map[*iter] = iter;
            *iter = result;
        }
        return T;
    }
};

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution().dailyTemperatures(T);
    for (auto i : T)
        cout << i << endl;
}
