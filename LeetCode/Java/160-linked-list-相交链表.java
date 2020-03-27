/*
 * @lc app=leetcode.cn id=160 lang=java
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; next = null; } }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        ListNode pa = headA, pb = headB;
        while (pa != pb) {
            pa = pa.next;
            pb = pb.next;
            if (pa == null && pb == null)
                return null;
            if (pa == null)
                pa = headB;
            if (pb == null)
                pb = headA;
        }
        return pa;
    }
}
// @lc code=end
