class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        int64_t presum = 0;
        multiset<int64_t> S;
        S.insert(0);
        int ret = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            ret += distance(S.lower_bound(presum-upper),S.upper_bound(presum-lower));
            S.insert(presum);
        }
        return ret;
    }        
};
