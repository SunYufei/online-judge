/*
 @lc app=leetcode.cn id=142 lang=java
 *
 [142] 环形链表 II
 */

// @lc code=start
// /**
//  Definition for singly-linked list.
//  class ListNode {
//      int val;
//      ListNode next;
//      ListNode(int x) {
//          val = x;
//          next = null;
//      }
//  }
//  */

// class ListNode {
//     int val;
//     ListNode next;

//     ListNode(int x) {
//         val = x;
//         next = null;
//     }
// }

import java.util.HashSet;

public class Solution {
    public ListNode detectCycle(ListNode head) {
        var visited = new HashSet<ListNode>();

        ListNode node = head;
        while (node != null) {
            if (visited.contains(node))
                return node;
            visited.add(node);
            node = node.next;
        }

        return null;
    }
}
// @lc code=end
