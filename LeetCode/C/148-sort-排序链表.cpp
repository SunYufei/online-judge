/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // split
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = slow->next;
        slow->next = nullptr;
        // sort left & right
        ListNode *left = sortList(head);
        ListNode *right = sortList(p);
        // merge
        ListNode *res = new ListNode(-1);
        p = res;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        p = res;
        res = res->next;
        delete p;
        return res;
    }
};
// @lc code=end
