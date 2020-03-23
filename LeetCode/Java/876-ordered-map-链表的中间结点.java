/*
 * @lc app=leetcode.cn id=876 lang=java
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode res = head, p = head;
        int count = 0;
        while (p != null) {
            ++count;
            p = p.next;
            if (count % 2 == 0)
                res = res.next;
        }
        return res;
    }
}
// @lc code=end
