package lc0020

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var data = map[string]bool{
	"":       true,
	"()":     true,
	"()[]{}": true,
	"(]":     false,
	"([)]":   false,
	"[":      false,
}

func TestIsValid(t *testing.T) {
	for k, v := range data {
		assert.Equal(t, v, IsValid(k))
	}
}
