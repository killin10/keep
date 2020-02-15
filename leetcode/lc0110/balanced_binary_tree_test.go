package lc0110

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  *TreeNode
	Expect bool
}{
	{
		&TreeNode{3,
			&TreeNode{Val: 9},
			&TreeNode{Val: 20, Left: &TreeNode{Val: 15}, Right: &TreeNode{Val: 7}},
		},
		true,
	},
	{
		&TreeNode{1,
			&TreeNode{Val: 2,
				Left: &TreeNode{Val: 3,
					Left:  &TreeNode{Val: 4},
					Right: &TreeNode{Val: 4}},
				Right: &TreeNode{Val: 3}},
			&TreeNode{Val: 2},
		},
		false,
	},
}

func TestIsBalanced(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, isBalanced(v.Input))
		})
	}
}
