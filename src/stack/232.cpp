#include <stack>
#include <iostream>

using namespace std;
class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main() {
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    while (!q->empty())
        cout << q->pop() << endl;
    delete q;
}
