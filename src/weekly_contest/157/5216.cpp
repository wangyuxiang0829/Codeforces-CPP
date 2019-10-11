class Solution {
public:
    int countVowelPermutation(int n) {
        long long na = 1, ne = 1, ni = 1, no = 1, nu = 1;
        constexpr int M = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            auto ia = (nu + ni + ne) % M;
            auto ie = (na + ni) % M;
            auto ii = (ne + no) % M;
            auto io = ni;
            auto iu = (ni + no) % M;
            na = ia;
            ne = ie;
            ni = ii;
            no = io;
            nu = iu;
        }
        return (na + ne + ni + no + nu) % M;
    }
};
