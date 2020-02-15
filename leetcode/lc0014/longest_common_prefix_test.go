package lc0014

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = map[string][]string{
	"":   []string{},
	"ab": []string{"ab", "abc", "abcd"},
	"ac": []string{"acd", "ac2a", "acd5"},
	"a":  []string{"aa", "a"},
}

func TestLongestCommonPrefix(t *testing.T) {
	for k, v := range data {
		assert.Equal(t, k, LongestCommonPrefix(v))
	}
}

func TestLongestCommonPrefixWithHorizontalScanning(t *testing.T) {
	for k, v := range data {
		assert.Equal(t, k, LongestCommonPrefixWithHorizontalScanning(v))
	}
}

func TestLCPWithDivideAndConquer(t *testing.T) {
	for k, v := range data {
		assert.Equal(t, k, LCPWithDivideAndConquer(v))
	}
}
