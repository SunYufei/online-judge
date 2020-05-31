#include "main.h"

class Solution {
  public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *p = nullptr, *c = pHead, *t;
        while (c) {
            t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
        return p;
    }

    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr)
            return nullptr;
        if (pHead->next == nullptr)
            return pHead;
        auto last = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return last;
    }
};