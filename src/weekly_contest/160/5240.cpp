#include <vector>
#include <string>
#include <cassert>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxLength(vector<string> &arr) {
        auto aseq = dfs(arr.size() - 1, arr);
        int max_len = 0;
        for (const auto &seq : aseq) {
            int uchar[128] = {0};
            int len = 0;
            bool flag = true;
            for (const auto &s : seq) {
                for (auto c : s) {
                    if (uchar[c] != 0) {
                        flag = false;
                        break;
                    }
                    uchar[c] = 1;
                    len++;
                }
                if (!flag) break;
            }
            if (flag) max_len = max(len, max_len);
        }
        return max_len;
    }
private:
    vector<vector<string>> dfs(int i, vector<string> &arr) {
        if (i <= 0) return {{}, {arr[0]}};
        auto pre = dfs(i - 1, arr), cur = pre;
        for (auto &seq : cur)
            seq.push_back(arr[i]);
        pre.insert(pre.end(), make_move_iterator(cur.begin()), make_move_iterator(cur.end()));
        return pre;
    }
};

int main() {
    vector<string> arr = {"un", "iq", "ue"};
    assert(Solution().maxLength(arr) == 4);
}
