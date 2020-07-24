/*
 * @lc app=leetcode.cn id=190 lang=golang
 *
 * [190] 颠倒二进制位
 */
package leetcode

// @lc code=start
func reverseBits(num uint32) uint32 {
	var res uint32
	for i := 0; i < 32; i++ {
		res = (res << 1) + (num & 1)
		num >>= 1
	}
	return res
}

// @lc code=end
