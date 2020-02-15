// Package lc0021 solves leetcode problem 21 (Easy).
// https://leetcode.com/problems/merge-two-sorted-lists/description/
package lc0021

// ListNode is the type of singly-linked list node.
type ListNode struct {
	Val  int
	Next *ListNode
}

// MergeTwoLists merge two sorted singly-linked lists.
func MergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{Val: -1}
	last := head

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			last.Next = l1
			l1 = l1.Next
		} else {
			last.Next = l2
			l2 = l2.Next
		}
		last = last.Next
	}

	if l1 != nil {
		last.Next = l1
	} else {
		last.Next = l2
	}

	return head.Next
}

// MergeTwoListsByRecursion merge 2 sorted lists using recursion.
func MergeTwoListsByRecursion(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = MergeTwoListsByRecursion(l1.Next, l2)
		return l1
	}
	l2.Next = MergeTwoListsByRecursion(l1, l2.Next)
	return l2
}
