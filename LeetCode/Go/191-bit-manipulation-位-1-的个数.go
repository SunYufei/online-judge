/*
 * @lc app=leetcode.cn id=191 lang=golang
 *
 * [191] 位1的个数
 */
package leetcode

// @lc code=start
func hammingWeight(num uint32) int {
	var count = 0
	for num != 0 {
		num &= (num - 1)
		count++
	}
	return count
}

// @lc code=end
