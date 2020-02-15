package lc0111

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  *TreeNode
	Expect int
}{
	{
		&TreeNode{3,
			&TreeNode{Val: 9},
			&TreeNode{Val: 20, Left: &TreeNode{Val: 15}, Right: &TreeNode{Val: 7}},
		},
		2,
	},
	{
		&TreeNode{1,
			&TreeNode{Val: 2},
			nil,
		},
		2,
	},
}

func TestMinDepth(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, minDepth(v.Input))
		})
	}
}
