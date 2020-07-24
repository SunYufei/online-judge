/*
 * @lc app=leetcode.cn id=461 lang=golang
 *
 * [461] 汉明距离
 */

package leetcode

// @lc code=start
func hammingDistance(x int, y int) int {
	n := x ^ y
	count := 0
	for n != 0 {
		n &= n - 1
		count++
	}
	return count
}

// @lc code=end
