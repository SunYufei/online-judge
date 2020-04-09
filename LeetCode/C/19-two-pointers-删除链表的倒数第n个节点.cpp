/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */
#include "main.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, *pre = nullptr, *cur = head;
        while (n--)
            p = p->next;
        while (p) {
            pre = cur;
            cur = cur->next;
            p = p->next;
        }
        if (pre != nullptr) {
            pre->next = cur->next;
            delete cur;
        } else {
            pre = head;
            head = head->next;
            delete pre;
        }
        return head;
    }
};
// @lc code=end
