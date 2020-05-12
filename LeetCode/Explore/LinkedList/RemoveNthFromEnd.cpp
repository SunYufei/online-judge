#include "../main.h"

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, *pre = nullptr, *cur = head;
        while (n--)
            p = p->next;
        while (p) {
            pre = cur;
            cur = cur->next;
            p = p->next;
        }
        if (pre != nullptr) {
            pre->next = cur->next;
            delete cur;
        } else {
            pre = head;
            head = head->next;
            delete pre;
        }
        return head;
    }
};