package lc0083

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  []int
	Expect []int
}{
	{[]int{}, []int{}},
	{[]int{1, 1, 2}, []int{1, 2}},
	{[]int{1, 1, 2, 3, 3}, []int{1, 2, 3}},
}

func TestDeleteDuplicates(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, toSlice(DeleteDuplicates(toList(v.Input))))
		})
	}
}

func toSlice(head *ListNode) []int {
	r := []int{}
	for ; head != nil; head = head.Next {
		r = append(r, head.Val)
	}
	return r
}

func toList(l []int) *ListNode {
	head := &ListNode{0, nil}
	last := head
	for _, v := range l {
		last.Next = &ListNode{v, nil}
		last = last.Next
	}
	return head.Next
}
