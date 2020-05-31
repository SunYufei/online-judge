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

    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return pHead1 ? pHead1 : pHead2;
        ListNode *res;
        if (pHead1->val < pHead2->val) {
            res = pHead1;
            pHead1 = pHead1->next;
        } else {
            res = pHead2;
            pHead2 = pHead2->next;
        }
        res->next = Merge(pHead1, pHead2);
        return res;
    }
};