/*
 * @lc app=leetcode.cn id=189 lang=golang
 *
 * [189] 旋转数组
 */
package leetcode

// @lc code=start
func rotate(nums []int, k int) {
	reverse := func(l, r int) {
		for l < r {
			r--
			nums[l], nums[r] = nums[r], nums[l]
			l++
		}
	}
	n := len(nums)
	k %= n
	reverse(0, n)
	reverse(0, k)
	reverse(k, n)
}

// @lc code=end
