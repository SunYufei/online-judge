#include "main.h"

class Solution {
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        auto pa = pHead1, pb = pHead2;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
            if (pa == nullptr && pb == nullptr)
                return nullptr;
            if (pa == nullptr)
                pa = pHead2;
            if (pb == nullptr)
                pb = pHead1;
        }
        return pa;
    }
};