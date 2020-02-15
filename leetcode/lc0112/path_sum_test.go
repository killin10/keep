package lc0112

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	InputTree *TreeNode
	InputSum  int
	Expect    bool
}{
	{
		&TreeNode{5,
			&TreeNode{Val: 4, Left: &TreeNode{Val: 11, Left: &TreeNode{Val: 7}, Right: &TreeNode{Val: 2}}},
			&TreeNode{Val: 8, Left: &TreeNode{Val: 13}, Right: &TreeNode{Val: 4, Right: &TreeNode{Val: 1}}},
		},
		22,
		true,
	},
}

func TestHasPathSum(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, hasPathSum(v.InputTree, v.InputSum))
		})
	}
}
