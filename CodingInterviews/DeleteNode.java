public class DeleteNode {
    public static void main(String[] args) {

    }

    private static ListNode deleteNode(ListNode head, int val) {
        if (head == null)
            return head;

        if (head.val == val)
            head = head.next;

        ListNode pre = head, cur = head.next;

        while (cur != null) {
            if (cur.val == val)
                pre.next = cur.next;
            cur = cur.next;
            pre = pre.next;
        }

        return head;
    }

    private class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}