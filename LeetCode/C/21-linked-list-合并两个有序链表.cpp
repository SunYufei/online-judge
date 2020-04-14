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
        ListNode head(-1), *p = &head;
        while (l1 && l2) {
            ListNode *t;
            if (l1->val < l2->val) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
            t->next = p->next;
            p->next = t;
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head.next;
    }
};
// @lc code=end
