/*
 * @lc app=leetcode.cn id=167 lang=golang
 *
 * [167] 两数之和 II - 输入有序数组
 */
// package leetcode

// @lc code=start
func twoSum(numbers []int, target int) []int {
	if len(numbers) == 0 {
		return []int{}
	}
	l, r := 0, len(numbers)-1
	for l < r {
		sum := numbers[l] + numbers[r]
		if sum == target {
			return []int{l + 1, r + 1}
		} else if sum < target {
			l++
		} else {
			r--
		}
	}
	return []int{l + 1, r + 1}
}

// @lc code=end
