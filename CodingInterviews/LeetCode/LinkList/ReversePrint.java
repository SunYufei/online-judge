package LinkList;

import java.util.Stack;

class Solution {
    public int[] reversePrint(ListNode head) {
        if (head == null)
            return new int[0];
        Stack<Integer> stack = new Stack<>();
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        int n = stack.size();
        int[] res = new int[n];
        for (int i = 0; i < n; i++)
            res[i] = stack.pop();
        return res;
    }
}