package lc0013

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestReverse(t *testing.T) {
	assert.Equal(t, 1, RomanToInt("I"))
	assert.Equal(t, 2, RomanToInt("II"))
	assert.Equal(t, 3, RomanToInt("III"))
	assert.Equal(t, 4, RomanToInt("IV"))
	assert.Equal(t, 5, RomanToInt("V"))
	assert.Equal(t, 6, RomanToInt("VI"))
	assert.Equal(t, 7, RomanToInt("VII"))
	assert.Equal(t, 8, RomanToInt("VIII"))
	assert.Equal(t, 9, RomanToInt("IX"))
	assert.Equal(t, 10, RomanToInt("X"))
	assert.Equal(t, 18, RomanToInt("XVIII"))
	assert.Equal(t, 43, RomanToInt("XLIII"))
	assert.Equal(t, 48, RomanToInt("XLVIII"))
	assert.Equal(t, 49, RomanToInt("XLIX"))
	assert.Equal(t, 99, RomanToInt("XCIX"))
}
