package lc0038

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  int
	Expect string
}{
	{1, "1"},
	{2, "11"},
	{3, "21"},
	{4, "1211"},
	{5, "111221"},
}

func TestCountAndSay(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, CountAndSay(v.Input))
		})
	}
}
