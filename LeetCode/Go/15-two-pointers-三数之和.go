/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */
package leetcode

// @lc code=start
import "sort"

func threeSum(nums []int) [][]int {
	var res = [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		var l, r = i + 1, len(nums) - 1
		for l < r {
			var sum = nums[i] + nums[l] + nums[r]
			if sum == 0 {
				res = append(res, []int{nums[i], nums[l], nums[r]})
				for l+1 < r && nums[l] == nums[l+1] {
					l++
				}
				for l < r-1 && nums[r] == nums[r-1] {
					r--
				}
				l, r = l+1, r-1
			} else if sum < 0 {
				l++
			} else {
				r--
			}
		}
	}
	return res
}

// @lc code=end
