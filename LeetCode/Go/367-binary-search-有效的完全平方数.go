/*
 * @lc app=leetcode.cn id=367 lang=golang
 *
 * [367] 有效的完全平方数
 */
package leetcode

// @lc code=start
func isPerfectSquare(num int) bool {
	if num == 1 {
		return true
	}
	for l, r := 0, num/2; l <= r; {
		m := l + (r-l)>>1
		square := m * m
		if square == num {
			return true
		} else if square > num {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return false
}

// @lc code=end
