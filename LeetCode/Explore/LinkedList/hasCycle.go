package linklist

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	var slow, fast = head, head.Next
	for fast != nil && fast.Next != nil {
		if fast == slow {
			return true
		}
		slow = slow.Next
		fast = fast.Next.Next
	}
	return false
}
