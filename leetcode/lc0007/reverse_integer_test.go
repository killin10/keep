package lc0007

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestReverse(t *testing.T) {
	assert.Equal(t, 321, Reverse(123))
	assert.Equal(t, -321, Reverse(-123))
	assert.Equal(t, 21, Reverse(120))
	assert.Equal(t, 0, Reverse(1534236469))
	assert.Equal(t, 0, Reverse(-2147483648))
}
