class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<int> group[501];
        for (int i = 0; i < groupSizes.size(); i++) {
            int groupSize = groupSizes[i];
            group[groupSize].push_back(i);
        }
        vector<vector<int>> result;
        for (int n = 1; n < 500; n++) {
            int num = group[n].size();
            if (num == 0) continue;
            for (int i = 0; i < num / n; i++)
                result.push_back(vector<int>(group[n].begin() + i * n, group[n].begin() + (i + 1) * n));
        }
        return result;
    }
};
