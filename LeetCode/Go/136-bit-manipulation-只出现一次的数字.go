/*
 * @lc app=leetcode.cn id=136 lang=golang
 *
 * [136] 只出现一次的数字
 */

package leetcode

// @lc code=start
func singleNumber(nums []int) int {
	var res int
	for _, num := range nums {
		res ^= num
	}
	return res
}

// @lc code=end
