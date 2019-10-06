class Solution {
public:
    int reverse(int x) {
        forward_list<int> digits;
        while (x) {
            digits.push_front(x % 10);
            x /= 10;
        }
        long long reverse = 0;
        int i = 0;
        for (auto digit : digits) {
            reverse += digit * pow(10, i++);
        }
        if (reverse > pow(2, 31) - 1 || reverse < -pow(2, 31))
            return 0;
        return reverse;
    }
};
