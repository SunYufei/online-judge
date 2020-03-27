package LinkList;

class Solution {
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