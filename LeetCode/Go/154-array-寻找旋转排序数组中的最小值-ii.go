/*
 * @lc app=leetcode.cn id=154 lang=golang
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
package leetcode

// @lc code=start
func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		p := l + (r-l)>>1
		if nums[p] < nums[r] {
			r = p
		} else if nums[p] > nums[r] {
			l = p + 1
		} else {
			r--
		}
	}
	return nums[l]
}

// @lc code=end
