#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head, *pre = dummy;
        while (cur) {
            ListNode *travel = dummy->next, *travel_pre = dummy;
            while (travel->val < cur->val) {
                travel_pre = travel;
                travel = travel->next;
            }
            if (travel == cur) {
                pre = cur;
                cur = cur->next;
                continue;
            }
            travel_pre->next = new ListNode(cur->val);
            travel_pre->next->next = travel;
            cur = cur->next;
            delete pre->next;
            pre->next = cur;
        }
        return dummy->next;
    }
};

void printList(ListNode *head) {
    if (!head) return;
    cout << head->val << ' ';
    printList(head->next);
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node4->next = node2;
    node2->next = node1;
    node1->next = node3;

    printList(Solution().insertionSortList(node4));
    cout << endl;
}
