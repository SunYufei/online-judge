#include "listnode.h"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *res = new ListNode(-1);
        while (head != nullptr) {
            ListNode *t = new ListNode(head->val);
            t->next = res->next;
            res->next = t;
            t = head;
            head = head->next;
            delete t;
        }
        ListNode *p = res;
        res = res->next;
        delete p;
        return res;
    }
};