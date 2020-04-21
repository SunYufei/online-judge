#include "main.h"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = nullptr, *c = head, *t;
        while (c) {
            t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
        return p;
    }
};