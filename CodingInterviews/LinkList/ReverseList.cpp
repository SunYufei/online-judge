#include "listnode.h"

class Solution {
  public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *head = new ListNode(-1);
        ListNode *p = pHead;
        while (p != nullptr) {
            ListNode *t = new ListNode(p->val);
            t->next = head->next;
            head->next = t;
            p = p->next;
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};