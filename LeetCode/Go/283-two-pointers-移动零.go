/*
 * @lc app=leetcode.cn id=283 lang=golang
 *
 * [283] 移动零
 */
package leetcode

// @lc code=start
func moveZeroes(nums []int) {
	for a, b := 0, 0; a < len(nums); a++ {
		if nums[a] != 0 {
			nums[a], nums[b] = nums[b], nums[a]
			b++
		}
	}
}

// @lc code=end
