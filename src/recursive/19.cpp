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
        if (helper(head, n) == n) return head->next;
        return head;
    }
private:
    int helper(ListNode *head, int n) {
        if (!head) return 0;
        int level = helper(head->next, n);
        if (level == n) {
            auto tmp = head->next;
            head->next = tmp->next;
//          delete tmp;
        }
        return level + 1;
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
    printList(Solution().removeNthFromEnd(&node1, 5));
}
