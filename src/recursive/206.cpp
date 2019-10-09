#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // iteration
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        auto cur = head;
        while (cur) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    // recursive
    ListNode *ReverseList(ListNode *head) {
        if (!head || !head->next) return head;
        auto p = ReverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

void printList(ListNode *head) {
    if (!head) return;
    cout << head->val << endl;
    printList(head->next);
}

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    printList(Solution().reverseList(&node1));
    printList(Solution().ReverseList(&node5));
}
