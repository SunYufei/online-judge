/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */
package leetcode

// @lc code=start
func twoSum(nums []int, target int) []int {
	m := map[int]int{}
	for i, v := range nums {
		if k, ok := m[target-v]; ok {
			return []int{k, i}
		}
		m[v] = i
	}
	return nil
}

// @lc code=end
