package lc0101

import (
	"fmt"
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  *TreeNode
	Expect bool
}{
	{
		&TreeNode{1,
			&TreeNode{2, &TreeNode{Val: 3}, &TreeNode{Val: 4}},
			&TreeNode{2, &TreeNode{Val: 4}, &TreeNode{Val: 3}},
		},
		true},
		{
		&TreeNode{1,
			&TreeNode{2, nil, &TreeNode{Val: 3}},
			&TreeNode{2, nil, &TreeNode{Val: 3}},
		},
		false},
}

func TestIsSymmetric(t *testing.T) {
	for i, v := range data {
		t.Run(fmt.Sprintf("%v->%v", "Case" + strconv.Itoa(i), v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, isSymmetric(v.Input))
		})
	}
}
