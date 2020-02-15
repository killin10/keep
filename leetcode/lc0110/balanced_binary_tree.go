// Package lc0110 solves leetcode problem 110 (Easy).
// https://leetcode.com/problems/balanced-binary-tree/
package lc0110

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	_, balanced := depthAndBalanced(root)
	return balanced
}

func depthAndBalanced(tree *TreeNode) (int, bool) {
	if tree == nil {
		return 0, true
	}

	leftDepth, leftBalanced := depthAndBalanced(tree.Left)
	rightDepth, rightBalanced := depthAndBalanced(tree.Right)

	if !leftBalanced || !rightBalanced {
		return 0, false
	}

	return max(leftDepth, rightDepth) + 1, abs(leftDepth-rightDepth) <= 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}
