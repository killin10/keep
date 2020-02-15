package lc0070

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  int
	Expect int
}{
	{2, 2},
	{3, 3},
}

func TestClimbStairs(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, ClimbStairs(v.Input))
		})
	}
}
