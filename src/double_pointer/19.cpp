#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto first = dummy, second = dummy;
        n++;
        while (n--)
            first = first->next;
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
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
    printList(Solution().removeNthFromEnd(&node1, 2));
}
