package lc1431-array

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Candies      []int
	extraCandies int
	Expect       []bool
}{
	{
		[]int{2, 3, 5, 1, 3},
		3,
		[]bool{true, true, true, false, true},
	},
	{
		[]int{4, 2, 1, 1, 2},
		1,
		[]bool{true, false, false, false, false},
	},
}

func TestKidsWithCandies(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, kidsWithCandies(v.Candies, v.extraCandies))
		})
	}
}
