/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode *right, *p, *t;
        // split
        right = head, p = head;
        while (p && p->next) {
            right = right->next;
            p = p->next->next;
        }
        p = right;
        right = right->next;
        p->next = nullptr;
        // reverse
        p = nullptr;
        while (right) {
            t = right->next;
            right->next = p;
            p = right;
            right = t;
        }
        right = p;
        // insert
        p = head;
        while (p && right) {
            t = right;
            right = right->next;
            t->next = p->next;
            p->next = t;
            p = t->next;
        }
    }
};
// @lc code=end
