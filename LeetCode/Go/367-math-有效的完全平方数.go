/*
 * @lc app=leetcode.cn id=367 lang=golang
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
func isPerfectSquare(num int) bool {
	t := 1
	for num > 0 {
		num -= t
		t += 2
	}
	return num == 0
}
// @lc code=end

