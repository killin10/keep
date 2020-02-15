package lc0118

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  int
	Expect [][]int
}{
	{
		5,
		[][]int{
			[]int{1},
			[]int{1, 1},
			[]int{1, 2, 1},
			[]int{1, 3, 3, 1},
			[]int{1, 4, 6, 4, 1},
		},
	},
}

func TestGenerate(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, generate(v.Input))
		})
	}
}
