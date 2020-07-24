/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] x 的平方根
 */
package leetcode

// @lc code=start
func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	l, r := 2, x>>1
	for l <= r {
		m := l + (r-l)>>1
		t := m * m
		if t > x {
			r = m - 1
		} else if t < x {
			l = m + 1
		} else {
			return m
		}
	}
	return r
}

// @lc code=end
