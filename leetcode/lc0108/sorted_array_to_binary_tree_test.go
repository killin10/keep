package lc0108

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  []int
	Expect *TreeNode
}{
	{
		[]int{-10, -3, 0, 5, 9},
		&TreeNode{0,
			&TreeNode{Val: -3, Left: &TreeNode{Val: -10}},
			&TreeNode{Val: 9, Left: &TreeNode{Val: 5}},
		},
	},
}

func TestLevelOrderBottom(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, sortedArrayToBST(v.Input))
		})
	}
}
