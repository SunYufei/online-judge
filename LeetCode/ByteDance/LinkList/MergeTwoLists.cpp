#include "listnode.h"

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            ListNode *t;
            if (l1->val < l2->val) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
            t->next = p->next;
            p->next = t;
            p = p->next;
        }
        p->next = l1 != nullptr ? l1 : l2;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};