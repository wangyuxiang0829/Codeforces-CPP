class Solution {
public:
    int getDecimalValue(ListNode *head) {
        vector<int> digits;
        while(head) {
            digits.push_back(head->val);
            head = head->next;
        }
        int sum = 0;
        for (int i = digits.size() - 1, j = 0; i >= 0; i--, j++)
            sum += digits[i] * pow(2, j);
        return sum;
    }
};
