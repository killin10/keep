package lc0066

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  []int
	Expect []int
}{
	{[]int{0}, []int{1}},
	{[]int{1, 2, 3}, []int{1, 2, 4}},
	{[]int{9, 8, 9}, []int{9, 9, 0}},
	{[]int{9, 9, 9}, []int{1, 0, 0, 0}},
}

func TestPlusOne(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, PlusOne(v.Input))
		})
	}
}
