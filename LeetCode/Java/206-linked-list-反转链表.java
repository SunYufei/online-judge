/*
 * @lc app=leetcode.cn id=206 lang=java
 *
 * [206] 反转链表
 */

// @lc code=start
//
// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; }
// }
//

// class ListNode {
//     int val;
//     ListNode next;

//     ListNode(int x) {
//         val = x;
//     }
// }

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newHead = null;
        ListNode t;

        while (head != null) {
            t = head.next;
            head.next = newHead;
            newHead = head;
            head = t;
        }

        return newHead;
    }
}
// @lc code=end
