// Package lc0083 solves leetcode problem 83 (Easy).
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
package lc0083

// ListNode defines a node of list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// DeleteDuplicates removes duplicated nodes from given list.
func DeleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	for last, next := head, head.Next; next != nil; next = next.Next {
		if next.Val == last.Val {
			last.Next = nil
		} else {
			last.Next = next
			last = next
		}
	}
	return head
}
