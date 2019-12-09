class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        while(n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int sum = 0, pro = 1;
        for (auto digit : digits) {
            sum += digit;
            pro *= digit;
        }
        return pro - sum;
    }
};
