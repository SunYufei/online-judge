#include "../../main.h"

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2;
        ListNode *head = new ListNode(-1), *k = head;
        while (p != nullptr && q != nullptr) {
            ListNode *t;
            if (p->val < q->val) {
                t = new ListNode(p->val);
                p = p->next;
            } else {
                t = new ListNode(q->val);
                q = q->next;
            }
            t->next = k->next;
            k->next = t;
            k = k->next;
        }
        k->next = p != nullptr ? p : q;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};