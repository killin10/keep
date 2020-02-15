// Package lc0111 solves leetcode problem 111 (Easy).
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
package lc0111

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftDepth, rightDepth := minDepth(root.Left), minDepth(root.Right)

	if leftDepth == 0 || rightDepth == 0 {
		return leftDepth + rightDepth + 1
	}
	if leftDepth < rightDepth {
		return leftDepth + 1
	}
	return rightDepth + 1
}
