class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};
        using Interval = vector<int>;
        sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2) {
            return i1[0] < i2[0];
        });
        vector<Interval> result{intervals[0]};
        for (const auto &i : intervals) {
            if (auto end = result.back().at(1); i[0] <= end) {
                if (end < i[1])
                    result.back().at(1) = i[1];
            }
            else {
                result.push_back(i);
            }
        }
        return result;
    }
};
