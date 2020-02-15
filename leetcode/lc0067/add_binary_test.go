package lc0067

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	InputA string
	InputB string
	Expect string
}{
	{"11", "1", "100"},
	{"1101", "1010", "10111"},
	{"0", "0", "0"},
}

func TestAddBinary(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v|%v->%v", v.InputA, v.InputB, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, AddBinary(v.InputA, v.InputB))
		})
	}
}
