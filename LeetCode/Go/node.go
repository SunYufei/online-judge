package leetcode

// TreeNode tree node of bin tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Node definition for a Node
type Node struct {
	Val      int
	Children []*Node
}
