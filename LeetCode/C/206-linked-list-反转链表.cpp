/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = new ListNode(-1);
        ListNode *t;
        while (head != nullptr) {
            t = head;
            head = head->next;
            t->next = p->next;
            p->next = t;
        }
        t = p;
        p = p->next;
        delete t;
        return p;
    }
};
// @lc code=end
