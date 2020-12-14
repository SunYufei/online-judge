package coding

// Level Order I
func levelOrder1BFS(root *TreeNode) []int {
	var res = make([]int, 0)
	var q = make([]*TreeNode, 0)
	if root != nil {
		q = append(q, root)
	}
	for len(q) != 0 {
		var size = len(q)
		for i := 0; i < size; i++ {
			var front = q[0]
			q = q[1:]
			res = append(res, front.Val)
			if front.Left != nil {
				q = append(q, front.Left)
			}
			if front.Right != nil {
				q = append(q, front.Right)
			}
		}
	}
	return res
}

// Level Order II
func levelOrder2DFS(root *TreeNode) [][]int {
	var res = make([][]int, 0)

	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		if level == len(res) {
			res = append(res, make([]int, 0))
		}
		res[level] = append(res[level], root.Val)
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	}

	dfs(root, 0)
	return res
}

func levelOrder2BFS(root *TreeNode) [][]int {
	var res = make([][]int, 0)
	var q = make([]*TreeNode, 0)
	if root != nil {
		q = append(q, root)
	}
	for len(q) != 0 {
		var level = make([]int, 0)
		var size = len(q)
		for i := 0; i < size; i++ {
			var front = q[0]
			q = q[1:]
			level = append(level, front.Val)
			if front.Left != nil {
				q = append(q, front.Left)
			}
			if front.Right != nil {
				q = append(q, front.Right)
			}
		}
		res = append(res, level)
	}
	return res
}

// Level Order III
func levelOrder3DFS(root *TreeNode) [][]int {
	var res = make([][]int, 0)

	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		if level == len(res) {
			res = append(res, make([]int, 0))
		}
		res[level] = append(res[level], root.Val)
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	}

	dfs(root, 0)
	for i := 0; i < len(res); i++ {
		if i&1 == 1 {
			l, r := 0, len(res[i])-1
			for l < r {
				res[i][l], res[i][r] = res[i][r], res[i][l]
				l++
				r--
			}
		}
	}
	return res
}

func levelOrder3BFS(root *TreeNode) [][]int {
	var res = make([][]int, 0)
	var q = make([]*TreeNode, 0)
	if root != nil {
		q = append(q, root)
	}
	var left = true
	for len(q) != 0 {
		var level = make([]int, 0)
		var size = len(q)
		for i := 0; i < size; i++ {
			var front = q[0]
			q = q[1:]
			level = append(level, front.Val)
			if front.Left != nil {
				q = append(q, front.Left)
			}
			if front.Right != nil {
				q = append(q, front.Right)
			}
		}
		if left == false {
			l, r := 0, len(level)-1
			for l < r {
				level[l], level[r] = level[r], level[l]
				l++
				r--
			}
		}
		left = !left
		res = append(res, level)
	}
	return res
}
