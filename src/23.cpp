#include <vector>
#include <limits>
#include <iostream>
#include <initializer_list>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(std::initializer_list<int> values) : ListNode(0) {
        if (values.begin() == values.end()) return;
        val = *values.begin();
        ListNode **current = &next;
        for (auto iter = values.begin() + 1; iter != values.end(); ++iter) {
            *current = new ListNode(*iter);
            current = &((*current)->next);
        }
    }
};

class Solution {
private:
    void mergeHead(std::vector<ListNode *> &lists, ListNode *&head) {
        int min = std::numeric_limits<int>::max(), min_list = -1;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                min_list = i;
            }
        }
        if (min_list >= 0) {
            head = new ListNode(min);
            lists[min_list] = lists[min_list]->next;
            mergeHead(lists, head->next);
        }
    }

public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *head = nullptr;
        mergeHead(lists, head);
        return head;
    }
};

int main() {
    Solution s;
    auto head1 = new ListNode{1, 4, 5};
    auto head2 = new ListNode{1, 3, 4};
    auto head3 = new ListNode{2, 6};
    std::vector<ListNode *> lists{head1, head2, head3};
    auto root = s.mergeKLists(lists);
    while (root) {
        std::cout << root->val << " ";
        root = root->next;
    }
    std::cout << std::endl;
}

