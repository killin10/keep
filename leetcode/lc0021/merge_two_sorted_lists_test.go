package lc0021

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = [][][]int{
	{{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
	{{}, {1, 3, 4}, {1, 3, 4}},
}

func TestMergeTwoLists(t *testing.T) {
	for _, v := range data {
		assert.Equal(t, v[2], toSlice(MergeTwoLists(toList(v[0]), toList(v[1]))))
	}
}

func TestMergeTwoListsByRecursion(t *testing.T) {
	for _, v := range data {
		assert.Equal(t, v[2], toSlice(MergeTwoListsByRecursion(toList(v[0]), toList(v[1]))))
	}
}

func toList(l []int) *ListNode {
	if len(l) == 0 {
		return nil
	}
	r := &ListNode{Val: l[0]}
	last := r
	for i := 1; i < len(l); i++ {
		last.Next = &ListNode{Val: l[i]}
		last = last.Next
	}
	return r
}

func toSlice(l *ListNode) []int {
	var s []int
	for l != nil {
		s = append(s, l.Val)
		l = l.Next
	}
	return s
}
