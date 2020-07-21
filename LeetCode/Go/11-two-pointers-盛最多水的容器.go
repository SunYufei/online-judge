/*
 * @lc app=leetcode.cn id=11 lang=golang
 *
 * [11] 盛最多水的容器
 */
package leetcode

// @lc code=start
func maxArea(height []int) int {
	var max = func(i, j int) int {
		if i > j {
			return i
		} else {
			return j
		}
	}

	var res = 0
	var l, r = 0, len(height) - 1
	for l < r {
		var h int
		if height[l] < height[r] {
			h = height[l]
			l++
		} else {
			h = height[r]
			r--
		}
		res = max(res, h*(r-l+1))
	}
	return res
}

// @lc code=end
