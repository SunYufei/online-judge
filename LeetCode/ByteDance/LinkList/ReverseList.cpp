#include "listnode.h"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *res = new ListNode(-1);
        ListNode *p = res, *q = head;
        while (q) {
            ListNode *t = new ListNode(q->val);
            t->next = p->next;
            p->next = t;
            q = q->next;
        }
        p = res;
        res = res->next;
        delete p;
        return res;
    }
};