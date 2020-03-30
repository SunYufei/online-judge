#include "listnode.h"

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *p = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int a = l1 != nullptr ? l1->val : 0;
            int b = l2 != nullptr ? l2->val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0)
            p->next = new ListNode(carry);
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};