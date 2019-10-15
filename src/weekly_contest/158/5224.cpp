class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        constexpr int M = 1e9 + 7;
        vector<vector<int>> pre;
        for (auto k : rollMax)
            pre.push_back(vector<int>(k));
        auto cur(pre);
        for (auto &j : pre)
            j[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    if (j != k)
                        for (auto t : pre[k]) {
                            cur[j][0] += t;
                            cur[j][0] %= M;
                        }
                    else
                        for (int m = 0; m < rollMax[k] - 1; m++)
                            cur[j][m + 1] = pre[k][m];
            pre = cur;
            for (auto &i : cur)
                for (auto &j : i)
                    j = 0;
        }
        int sum = 0;
        for (auto &i : pre)
            for (auto j : i) {
                sum += j;
                sum %= M;
            }
        return sum;
    }
};
