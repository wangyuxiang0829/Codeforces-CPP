#include <vector>
#include <bitset>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        auto result = dfs(n, n);
        vector<int> answer;
        int pos = 0;
        for (int i = 0; i < result.size(); ++i) {
            int val = result[i].to_ulong();
            answer.push_back(val);
            if (val == start) pos = i;
        }
        if (pos != 0) {
            auto before = vector<int>(answer.begin(), answer.begin() + pos);
            auto after  = vector<int>(answer.begin() + pos, answer.end());
            after.insert(after.end(), make_move_iterator(before.begin()), make_move_iterator(before.end()));
            answer = move(after);
        }
        return answer;
    }
private:
    vector<bitset<16>> dfs(int i, int n) {
        if (i < 1) return {bitset<16>()};
        auto &&right = dfs(i - 1, n);
        vector<bitset<16>> left(right.rbegin(), right.rend());
        for_each(right.begin(), right.end(), [=](bitset<16> &a) { a.set(i - 1); });
        left.insert(left.end(), make_move_iterator(right.begin()), make_move_iterator(right.end()));
        return left;
    }
};

ostream &operator<<(ostream &os, const vector<int> &v) {
    for (auto i : v)
        os << i << ' ';
    return os;
}

int main() {
    cout << Solution().circularPermutation(2, 3) << endl;
}
