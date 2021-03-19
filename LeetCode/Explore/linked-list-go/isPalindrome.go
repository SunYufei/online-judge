package linklist

func isPalindrome(head *ListNode) bool {
	var slow, fast = head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	if fast != nil {
		slow = slow.Next
	}

	var reverse = func(head *ListNode) *ListNode {
		var p, c, t *ListNode = nil, head, nil
		for c != nil {
			t = c.Next
			c.Next = p
			p = c
			c = t
		}
		return p
	}

	var left, right = head, reverse(slow)
	for right != nil {
		if left.Val != right.Val {
			return false
		}
		left = left.Next
		right = right.Next
	}
	return true
}
