#include "../main.h"

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        auto p = head;
        while (p) {
            if (st.insert(p).second == false)
                return p;
            p = p->next;
        }
        return nullptr;
    }
};