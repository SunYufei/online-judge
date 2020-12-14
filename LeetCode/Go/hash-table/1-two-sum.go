package hashtable

/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	if len(nums) < 2 {
		return nil
	}
	mp := map[int]int{}
	for i, num := range nums {
		if v, ok := mp[target-num]; ok {
			return []int{v, i}
		}
		mp[num] = i
	}
	return nil
}

// @lc code=end
