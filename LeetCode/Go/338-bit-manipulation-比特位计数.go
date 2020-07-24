/*
 * @lc app=leetcode.cn id=338 lang=golang
 *
 * [338] 比特位计数
 */
package leetcode

// @lc code=start
func countBits(num int) []int {
	var bits = make([]int, num+1)
	for i := 1; i <= num; i++ {
		bits[i] = bits[i&(i-1)] + 1
	}
	return bits
}

// @lc code=end
