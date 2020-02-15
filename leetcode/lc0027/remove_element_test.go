package lc0027

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

type record struct {
	Input  []int
	Val    int
	Length int
}

func setUp() []record {
	return []record{
		{[]int{}, 2, 0},
		{[]int{3, 2, 2, 3}, 3, 2},
		{[]int{1}, 1, 0},
		{[]int{1, 1}, 1, 0},
	}
}

func TestRemoveElement(t *testing.T) {
	for _, v := range setUp() {
		t.Run(fmt.Sprintf("%v -> %v", v.Input, v.Val), func(t *testing.T) {
			assert.Equal(t, v.Length, RemoveElement(v.Input, v.Val))
		})
	}
}

func TestRemoveElementUnordered(t *testing.T) {
	for _, v := range setUp() {
		t.Run(fmt.Sprintf("%v -> %v", v.Input, v.Val), func(t *testing.T) {
			assert.Equal(t, v.Length, RemoveElementUnordered(v.Input, v.Val))
		})
	}
}
