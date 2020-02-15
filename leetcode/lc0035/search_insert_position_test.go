package lc0035

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Array  []int
	Target int
	Index  int
}{
	{[]int{1, 3, 5, 6}, 5, 2},
	{[]int{1, 3, 5, 6}, 2, 1},
	{[]int{1, 3, 5, 6}, 7, 4},
	{[]int{1, 3, 5, 6}, 0, 0},
}

func TestSearchInsertRecursion(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Array, v.Target), func(t *testing.T) {
			assert.Equal(t, v.Index, SearchInsertRecursion(v.Array, v.Target))
		})
	}
}

func TestSearchInsert(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Array, v.Target), func(t *testing.T) {
			assert.Equal(t, v.Index, SearchInsert(v.Array, v.Target))
		})
	}
}
