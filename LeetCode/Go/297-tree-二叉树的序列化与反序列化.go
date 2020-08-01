/*
 * @lc app=leetcode.cn id=297 lang=golang
 *
 * [297] 二叉树的序列化与反序列化
 */
// package leetcode

import (
	"strconv"
	"strings"
)

// @lc code=start
type Codec struct{}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	var builder = strings.Builder{}
	var q = []*TreeNode{}
	q = append(q, root)
	for len(q) != 0 {
		var front = q[0]
		q = q[1:]
		if front != nil {
			builder.WriteString(strconv.Itoa(front.Val))
			builder.WriteRune(',')
			q = append(q, front.Left)
			q = append(q, front.Right)
		} else {
			builder.WriteString("null,")
		}
	}
	return builder.String()
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	var nodes = []*TreeNode{}
	var start, end = 0, 0
	for end < len(data) {
		for end = start; end < len(data); end++ {
			if data[end] == ',' {
				break
			}
		}
		var substr = data[start:end]
		if substr == "null" {
			nodes = append(nodes, nil)
		} else {
			var data, _ = strconv.Atoi(substr)
			nodes = append(nodes, &TreeNode{Val: data})
		}
		start = end + 1
	}
	var root = nodes[0]
	var cur = root
	for i, j := 1, 1; i < len(nodes) && j < len(nodes); j++ {
		if cur == nil {
			cur = nodes[j]
			continue
		}
		cur.Left = nodes[i]
		cur.Right = nodes[i+1]
		cur = nodes[j]
		i += 2
	}
	return root
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * data := obj.serialize(root);
 * ans := obj.deserialize(data);
 */
// @lc code=end
