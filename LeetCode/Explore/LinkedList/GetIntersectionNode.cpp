#include "main.h"

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        auto pa = headA, pb = headB;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
            if (pa == nullptr && pb == nullptr)
                return nullptr;
            if (pa == nullptr)
                pa = headB;
            if (pb == nullptr)
                pb = headA;
        }
        return pa;
    }
};