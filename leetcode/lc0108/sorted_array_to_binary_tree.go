// Package lc0108 solves leetcode problem 108 (Easy).
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
package lc0108

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}

	mid := len(nums) / 2
	return &TreeNode{
		nums[mid],
		sortedArrayToBST(nums[0:mid]),
		sortedArrayToBST(nums[mid+1:]),
	}
}
