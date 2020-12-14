package coding

func verifyPostorder(postorder []int) bool {
	if len(postorder) == 0 {
		return true
	}
	var check func(int, int) bool
	check = func(left, right int) bool {
		if left > right {
			return true
		}
		var root = postorder[right]
		var k = left
		for k < right && postorder[k] < root {
			k++
		}
		for i := k; i < right; i++ {
			if postorder[i] < root {
				return false
			}
		}
		return check(left, k-1) && check(k, right-1)
	}
	return check(0, len(postorder)-1)
}
