package lc0121

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  []int
	Expect int
}{
	{
		[]int{7, 1, 5, 3, 6, 4},
		5,
	},
	{
		[]int{7, 6, 4, 3, 1},
		0,
	},
	{
		[]int{2, 4, 1},
		2,
	},
	{
		[]int{},
		0,
	},
	{
		[]int{2, 1, 2, 1, 0, 1, 2},
		2,
	},
}

func TestGenerate(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, maxProfit(v.Input))
		})
	}
}
