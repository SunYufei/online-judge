/*
 * @lc app=leetcode.cn id=155 lang=golang
 *
 * [155] 最小栈
 */
package leetcode

import "math"

// @lc code=start
type MinStack struct {
	Stack []int
	Min   int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	stack := MinStack{}
	stack.Min = math.MaxInt64
	return stack
}

func (this *MinStack) Push(x int) {
	if x <= this.Min {
		this.Stack = append(this.Stack, this.Min)
		this.Min = x
	}
	this.Stack = append(this.Stack, x)
}

func (this *MinStack) Pop() {
	var top = this.Top()
	this.Stack = this.Stack[:len(this.Stack)-1]
	if top == this.Min {
		this.Min = this.Top()
		this.Stack = this.Stack[:len(this.Stack)-1]
	}
}

func (this *MinStack) Top() int {
	return this.Stack[len(this.Stack)-1]
}

func (this *MinStack) GetMin() int {
	return this.Min
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
// @lc code=end
