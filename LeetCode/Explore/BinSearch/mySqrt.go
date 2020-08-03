package leetcode

func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	var l, r = 2, x >> 1
	for l <= r {
		var m = l + (r-l)>>1
		var t = m * m
		if t == x {
			return m
		} else if t < x {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return r
}
