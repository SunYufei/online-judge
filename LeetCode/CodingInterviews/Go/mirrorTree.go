package coding

func mirrorTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = mirrorTree(root.Left)
	root.Right = mirrorTree(root.Right)
	root.Left, root.Right = root.Right, root.Left
	return root
}
