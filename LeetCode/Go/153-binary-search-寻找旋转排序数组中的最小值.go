/*
 * @lc app=leetcode.cn id=153 lang=golang
 *
 * [153] 寻找旋转排序数组中的最小值
 */
// package leetcode

// @lc code=start
func findMin(nums []int) int {
	if nums[0] > nums[len(nums)-1] {
		l, r := 0, len(nums)-1
		for l <= r {
			m := l + (r-l)>>1
			if nums[m] > nums[m+1] {
				return nums[m+1]
			} else if nums[m] < nums[l] {
				r = m - 1
			} else {
				l = m + 1
			}
		}
	}
	return nums[0]
}

// @lc code=end
