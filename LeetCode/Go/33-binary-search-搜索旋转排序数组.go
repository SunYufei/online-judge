/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */
package leetcode

// @lc code=start
func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	for l <= r {
		m := l + (r-l)>>1
		if nums[m] == target {
			return m
		} else if nums[l] <= nums[m] {
			// left grow
			if nums[l] <= target && target <= nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		} else {
			// right grow
			if nums[m] <= target && target <= nums[r] {
				l = m + 1
			} else {
				r = m - 1
			}
		}
	}
	return -1
}

// @lc code=end
