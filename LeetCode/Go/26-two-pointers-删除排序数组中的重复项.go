/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除排序数组中的重复项
 */
package leetcode

// @lc code=start
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	var p = 0
	for _, num := range nums {
		if nums[p] != num {
			p += 1
			nums[p] = num
		}
	}
	return p + 1
}

// @lc code=end
