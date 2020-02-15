package lc0026

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = [][][]int{
	{{1, 1, 2}, {1, 2}, {2}},
	{{}, {}, {0}},
	{{1}, {1}, {1}},
	{{1, 2, 2, 3, 4, 4}, {1, 2, 3, 4}, {4}},
}

func TestRemoveDuplicates(t *testing.T) {
	for _, v := range data {
		length := RemoveDuplicates(v[1])
		assert.Equal(t, v[2][0], length)
	}
}
