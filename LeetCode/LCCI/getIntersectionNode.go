package lcci

func getIntersectionNode(a, b *ListNode) *ListNode {
	if a == nil || b == nil {
		return nil
	}
	pa, pb := a, b
	for pa != pb {
		pa = pa.Next
		pb = pb.Next
		if pa == nil && pb == nil {
			return nil
		}
		if pa == nil {
			pa = b
		}
		if pb == nil {
			pb = a
		}
	}
	return pa
}
