package lc0028

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = []struct {
	haystack string
	needle   string
	index    int
}{
	{"hello", "ll", 2},
	{"aaaaa", "bba", -1},
	{"hh", "hhhh", -1},
	{"", "h", -1},
}

func TestStrStr(t *testing.T) {
	for _, v := range data {
		t.Run(fmt.Sprintf("%s->%s", v.haystack, v.needle), func(t *testing.T) {
			assert.Equal(t, v.index, StrStr(v.haystack, v.needle))
		})
	}
}
