// Package lc0104 solves leetcode problem 104 (Easy).
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
package lc0104

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftDepth, rightDepth := maxDepth(root.Left), maxDepth(root.Right)
	if leftDepth > rightDepth {
		return leftDepth + 1
	}
	return rightDepth + 1
}
