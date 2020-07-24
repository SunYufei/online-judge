/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
package leetcode

// @lc code=start
func searchRange(nums []int, target int) []int {
	l, r := 0, len(nums)-1
	for l <= r {
		m := l + (r-l)>>1
		if nums[m] == target {
			for nums[l] < nums[m] {
				l++
			}
			for nums[r] > nums[m] {
				r--
			}
			return []int{l, r}
		} else if nums[m] < target {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return []int{-1, -1}
}

// @lc code=end
