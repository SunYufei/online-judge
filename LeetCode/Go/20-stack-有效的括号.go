/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 */
package leetcode

// @lc code=start
func isValid(s string) bool {
	var stack = []rune{}
	for _, c := range s {
		if c == ')' || c == ']' || c == '}' {
			if len(stack) == 0 || stack[len(stack)-1] != c {
				return false
			} else {
				stack = stack[:len(stack)-1]
			}
		} else if c == '(' {
			stack = append(stack, ')')
		} else if c == '[' {
			stack = append(stack, ']')
		} else if c == '{' {
			stack = append(stack, '}')
		}
	}
	return len(stack) == 0
}

// @lc code=end
