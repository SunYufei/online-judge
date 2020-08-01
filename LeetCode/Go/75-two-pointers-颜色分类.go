/*
 * @lc app=leetcode.cn id=75 lang=golang
 *
 * [75] 颜色分类
 */
package leetcode

// @lc code=start
func sortColors(nums []int) {
	var p0, p2 = 0, len(nums) - 1
	var cur = 0
	for cur <= p2 {
		if nums[cur] == 0 {
			nums[p0], nums[cur] = nums[cur], nums[p0]
			p0, cur = p0+1, cur+1
		} else if nums[cur] == 2 {
			nums[cur], nums[p2] = nums[p2], nums[cur]
			p2--
		} else {
			cur++
		}
	}
}

// @lc code=end
