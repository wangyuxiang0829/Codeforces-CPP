#include <stack>
#include <cassert>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        if (s.empty())
            s.push(make_pair(x, x));
        else {
            int m = min(s.top().second, x);
            s.push(make_pair(x, m));
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
private:
    stack<pair<int, int>> s;
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    assert(obj->getMin() == -3);
    obj->pop();
    assert(obj->top() == 0);
    assert(obj->getMin() == -2);
}
