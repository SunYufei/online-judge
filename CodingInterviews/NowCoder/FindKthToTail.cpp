#include "main.h"

class Solution {
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        auto p = pListHead, q = pListHead;
        while (k--) {
            if (q == nullptr)
                return nullptr;
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};