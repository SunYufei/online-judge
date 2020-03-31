#include "listnode.h"

class Solution {
  public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};