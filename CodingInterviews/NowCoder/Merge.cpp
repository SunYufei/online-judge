#include "main.h"

class Solution {
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode head(-1), *p = &head, *t;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                t = pHead1;
                pHead1 = pHead1->next;
            } else {
                t = pHead2;
                pHead2 = pHead2->next;
            }
            t->next = p->next;
            p->next = t;
            p = p->next;
        }
        p->next = pHead1 ? pHead1 : pHead2;
        return head.next;
    }
};