package lc0053

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  []int
	Expect int
}{
	{[]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
	{[]int{-1}, -1},
	{[]int{-2, -3, -1, -4, -5}, -1},
	{[]int{-2, 1}, 1},
}

func TestMaxSubArray(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, MaxSubArray(v.Input))
		})
	}
}

func TestMaxSubArrayByDivideAndConquer(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, MaxSubArrayByDivideAndConquer(v.Input))
		})
	}
}
