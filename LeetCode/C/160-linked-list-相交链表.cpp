/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
            if (pa == nullptr && pb == nullptr)
                return nullptr;
            if (pa == nullptr)
                pa = headB;
            if (pb == nullptr)
                pb = headA;
        }
        return pa;
    }
};
// @lc code=end
