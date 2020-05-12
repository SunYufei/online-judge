#include "../main.h"

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};