#include <cassert>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *left = head, *right = head, *pre = nullptr;
        while (right && right->next) {
            right = right->next->next;
            auto tmp = left->next;
            left->next = pre;
            pre  = left;
            left = tmp;
        }
        if (right) left = left->next;
        while (pre && left) {
            if (pre->val != left->val) return false;
            pre  = pre->next;
            left = left->next;
        }
        return true;
    }
};

int main() {
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    assert(Solution().isPalindrome(&node1) == false);
}
