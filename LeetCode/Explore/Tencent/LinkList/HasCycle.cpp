#include "../../main.h"

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};