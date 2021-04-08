/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto p1 = l1, p2 = l2;
        ListNode res(-1), *p = &res;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return res.next;
    }
};
// @lc code=end
