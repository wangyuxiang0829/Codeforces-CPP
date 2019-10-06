class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            *iter += 1;
            *iter = (*iter) % 10;
            if (*iter != 0) return digits;
        }
        
        vector<int> res(digits.size() + 1);
        res[0] = 1;
        
        return res;
    }
};
