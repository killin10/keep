package lc0058

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	Input  string
	Expect int
}{
	{"Hello world", 5},
	{"", 0},
	{"   ", 0},
	{"  abc  de  ", 2},
	{"  中文在Go 里面 ", 2},
}

func TestLengthOfLastWord(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%v->%v", v.Input, v.Expect), func(t *testing.T) {
			assert.Equal(t, v.Expect, LengthOfLastWord(v.Input))
		})
	}
}
