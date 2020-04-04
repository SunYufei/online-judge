/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
//
//  Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        ListNode *a = head, *b = head;
        for (int i = 0; i < k; i++) {
            if (b == nullptr)
                return head;
            b = b->next;
        }
        ListNode *new_head = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return new_head;
    }

  private:
    ListNode *reverse(ListNode *a, ListNode *b) {
        ListNode *pre = nullptr, *cur = a, *t;
        while (cur != b) {
            t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};
// @lc code=end
