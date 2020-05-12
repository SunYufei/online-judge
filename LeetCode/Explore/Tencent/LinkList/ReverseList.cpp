#include "../../main.h"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *cur = head, *t;
        while (cur) {
            t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};