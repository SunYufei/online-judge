/*
 * @lc app=leetcode.cn id=27 lang=golang
 *
 * [27] 移除元素
 */

package leetcode

// @lc code=start
func removeElement(nums []int, val int) int {
	var p = 0
	for _, num := range nums {
		if num != val {
			nums[p] = num
			p++
		}
	}
	return p
}

// @lc code=end
