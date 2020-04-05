/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        unordered_set<ListNode *> s;
        while (p) {
            if (s.insert(p).second == false)
                return p;
            p = p->next;
        }
        return nullptr;
    }
};
// @lc code=end
