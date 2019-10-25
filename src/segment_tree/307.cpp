#include <vector>
#include <cassert>
using namespace std;
constexpr int M(int i, int j) { return (i + j) / 2; }
constexpr int L(int i)        { return i * 2 + 1; }
constexpr int R(int i)        { return i * 2 + 2; }
class NumArray {
public:
    NumArray(const vector<int> &nums) : _right_end(nums.size() - 1) {
        if (_right_end < 0) return;
        _tree = vector<int>((_right_end + 1) * 4);
        build_tree(nums, 0, 0, _right_end);
    }

    void update(int i, int val) {
        update(0, 0, _right_end, i, val);
    }

    int sumRange(int i, int j) {
        return quary(0, 0, _right_end, i, j);
    }
private:
    int _right_end;
    vector<int> _tree;

    void build_tree(const vector<int> &nums, int n, int i, int j) {
        if (i == j) {
            _tree[n] = nums[i];
            return;
        }
        build_tree(nums, L(n), i, M(i, j));
        build_tree(nums, R(n), M(i, j) + 1, j);
        _tree[n] = _tree[L(n)] + _tree[R(n)];
    }

    void update(int n, int p, int q, int i, int v) {
        if (p == q) {
            _tree[n] = v;
            return;
        }
        if (i <= M(p, q)) update(L(n), p, M(p, q), i, v);
        else update(R(n), M(p, q) + 1, q, i, v);
        _tree[n] = _tree[L(n)] + _tree[R(n)];
    }

    int quary(int n, int p, int q, int l, int r) {
        if (l > q || r < p) return 0;
        if (p == q || (p >= l && q <= r)) return _tree[n];
        return quary(L(n), p, M(p, q), l, r) + quary(R(n), M(p, q) + 1, q, l, r);
    }
};

int main() {
    NumArray s({9, -8});
    s.update(0, 3);
    assert(s.sumRange(1, 1) == -8);
    assert(s.sumRange(0, 1) == -5);
    s.update(1, -3);
    assert(s.sumRange(0, 1) == 0);
}
