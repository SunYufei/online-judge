/*
 * @lc app=leetcode.cn id=66 lang=golang
 *
 * [66] 加一
 */
package leetcode

// @lc code=start
func plusOne(digits []int) []int {
	var carry = 1
	for i := len(digits) - 1; i >= 0; i-- {
		carry += digits[i]
		digits[i] = carry % 10
		carry /= 10
	}
	if carry != 0 {
		digits = append([]int{carry}, digits...)
	}
	return digits
}

// @lc code=end
