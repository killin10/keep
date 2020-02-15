package lc0069

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  int
	Expect int
}{
	{4, 2},
	{8, 2},
	{5, 2},
}

func TestSqrtNewton(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, SqrtNewton(v.Input))
		})
	}
}

func TestSqrtBinarySearch(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, SqrtBinarySearch(v.Input))
		})
	}
}
