package lc0107

import (
	"fmt"
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  *TreeNode
	Expect [][]int
}{
	{
		&TreeNode{3,
			&TreeNode{Val: 9},
			&TreeNode{20, &TreeNode{Val: 15}, &TreeNode{Val: 7}},
		},
		[][]int{
			[]int{15, 7},
			[]int{9, 20},
			[]int{3},
		},
	},
}

func TestLevelOrderBottom(t *testing.T) {
	for i, v := range data {
		t.Run(fmt.Sprintf("%v->%v", "Case"+strconv.Itoa(i), v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, levelOrderBottom(v.Input))
		})
	}
}
