// Package lc0007 solves leetcode problem 7 (Easy).
// https://leetcode.com/problems/reverse-integer/description/
package lc0007

const (
	maxUnit = ^uint32(0)
	// MaxInt is the value of int32.
	MaxInt = int32(maxUnit >> 1)
	// MinInt is the value of int32.
	MinInt = -MaxInt - 1
)

// Reverse reverse an integer(e.x. -123 => -321).
func Reverse(x int) int {
	r := 0
	for x != 0 {
		r = r*10 + (x % 10)
		x = x / 10
	}

	if r < 0 && r < int(MinInt) || r > 0 && r > int(MaxInt) {
		return 0
	}
	return r
}
