#include "../../main.h"

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto t = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(t);
        ListNode res(0), *p = &res;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return res.next;
    }
};