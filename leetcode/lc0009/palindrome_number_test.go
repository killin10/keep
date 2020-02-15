package lc0009

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestIsPalindrome(t *testing.T) {
	assert.True(t, IsPalindrome(121))
	assert.True(t, IsPalindrome(1221))
	assert.False(t, IsPalindrome(-121))
	assert.False(t, IsPalindrome(100))
}
