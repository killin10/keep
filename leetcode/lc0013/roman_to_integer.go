// Package lc0013 solves leetcode problem 13 (Easy).
// https://leetcode.com/problems/roman-to-integer/description/
package lc0013

var conversionTable = map[rune]int{
	'I': 1,
	'V': 5,
	'X': 10,
	'L': 50,
	'C': 100,
	'D': 500,
	'M': 1000,
}

// RomanToInt converts a roman numeral string to an ineger.
// 从右往左遍历，如果比上一个小就减去当前值，否则加上当前值即可。
func RomanToInt(s string) int {
	nr := 0
	last := 0
	current := 0

	runes := []rune(s)
	for i := len(s) - 1; i >= 0; i-- {
		current = conversionTable[runes[i]]
		if current < last {
			nr -= current
		} else {
			nr += current
		}
		last = current
	}

	return nr
}
