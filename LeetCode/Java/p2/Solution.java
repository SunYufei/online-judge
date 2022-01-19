package LeetCode.Java.p2;

import LeetCode.Java.node.ListNode;
/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode();
        ListNode p = res;
        int val = 0;

        while (l1 != null || l2 != null) {
            if (l1 != null)
                val += l1.val;
            if (l2 != null)
                val += l2.val;

            ListNode node = new ListNode(val % 10);
            val = val / 10;
            p.next = node;
            p = node;

            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }

        if (val != 0)
            p.next = new ListNode(val);

        return res.next;
    }
}
// @lc code=end
