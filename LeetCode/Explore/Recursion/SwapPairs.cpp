#include "../main.h"

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto last = swapPairs(head->next->next);
        auto res = head->next;
        res->next = head;
        head->next = last;
        return res;
    }
};