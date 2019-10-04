class Solution {
public:
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        const long long ab  = std::lcm(a, b);
        const long long bc  = std::lcm(b, c);
        const long long ac  = std::lcm(a, c);
        const long long abc = std::lcm(ab, c);

        auto U = [&](long long n) -> long long {
            return n/a+n/b+n/c-n/ab-n/bc-n/ac+n/abc;
        };

        long long L = 1, R = std::min(std::max({n * a, n * b, n * c}), static_cast<long long>(2e9)), RES = R;

        while (L <= R) {
            long long M = (L + R) / 2;
            if (U(M) < n) {
                RES = M;
                L = M + 1;
            }
            else
                R = M - 1;
        }

        return RES + 1;
    }
};
