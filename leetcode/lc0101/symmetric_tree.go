// Package lc0101 solves leetcode problem 101 (Easy).
// https://leetcode.com/problems/symmetric-tree/
package lc0101

import "container/list"

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	// return isSymmetricNodes([]*TreeNode{root})
	// return isSymmetricRecursive(root.Left, root.Right)
	queue := list.New()
	queue.PushBack(root.Left)
	queue.PushBack(root.Right)
	return isSymmetricIterative(queue)
}

func isSymmetricIterative(queue *list.List) bool {
	for queue.Len() != 0 {
		leftEle := queue.Front()
		queue.Remove(leftEle)
		rightEle := queue.Front()
		queue.Remove(rightEle)

		left, right := leftEle.Value.(*TreeNode), rightEle.Value.(*TreeNode)
		if left == nil && right == nil {
			continue
		}

		if left == nil || right == nil {
			return false
		}

		if left.Val != right.Val {
			return false
		}

		queue.PushBack(left.Left)
		queue.PushBack(right.Right)
		queue.PushBack(left.Right)
		queue.PushBack(right.Left)
	}
	return true
}

func isSymmetricRecursive(left *TreeNode, right *TreeNode) bool {
	if left == right {
		return true
	}

	if left == nil || right == nil {
		return false
	}

	if left.Val != right.Val {
		return false
	}

	return isSymmetricRecursive(left.Left, right.Right) && isSymmetricRecursive(left.Right, right.Left)
}

// naive solution
func isSymmetricNodes(nodes []*TreeNode) bool {
	hasNonNil := false
	children := make([]*TreeNode, 2*len(nodes))

	for i, j := 0, len(nodes)-1; i <= j; i, j = i+1, j-1 {
		left, right := nodes[i], nodes[j]

		if ((left == nil || right == nil) && left != right) ||
			(left != nil && right != nil && left.Val != right.Val) {
			return false
		}

		if left != nil {
			hasNonNil = true
			children[i*2] = left.Left
			children[i*2+1] = left.Right
		} else {
			children[i*2] = nil
			children[i*2+1] = nil
		}

		if right != left {
			if right != nil {
				hasNonNil = true
				children[j*2] = right.Left
				children[j*2+1] = right.Right
			} else {
				children[j*2] = nil
				children[j*2+1] = nil
			}
		}
	}

	if hasNonNil {
		return isSymmetricNodes(children)
	}
	return true
}
