#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
class Solution {
public:
    bool uniqueOccurrences(const vector<int> &arr) {
        unordered_map<int, int> occurrences;
        unordered_set<int> set;
        for (auto i : arr)
            occurrences[i]++;
        for (const auto &occurrence : occurrences) {
            if (set.find(occurrence.second) != set.end()) return false;
            set.insert(occurrence.second);
        }
        return true;
    }
};

int main() {
    assert(Solution().uniqueOccurrences({1, 2, 2, 1, 1, 3}) == true);
}
