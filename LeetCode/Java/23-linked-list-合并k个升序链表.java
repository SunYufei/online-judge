/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)
            return null;
        ListNode p = lists[0];
        for (int i = 1; i < lists.length; i++) {
            p = mergeTwo(p, lists[i]);
        }
        return p;
    }

    private ListNode mergeTwo(ListNode l1, ListNode l2) {
        ListNode res = new ListNode();
        ListNode p = res;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        if (l1 != null)
            p.next = l1;
        if (l2 != null)
            p.next = l2;
        return res.next;
    }
}
// @lc code=end
