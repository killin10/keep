// Package lc0038 solves leetcode problem 38 (Easy).
// https://leetcode.com/problems/count-and-say/description/
package lc0038

import (
	"strconv"
)

// CountAndSay generates the nth term of the count-and-say sequence with a given integer n
func CountAndSay(n int) string {
	r := "1"
	for ; n > 1; n-- {
		tr := ""
		var ch rune
		nr := 0
		for _, c := range r {
			if c == ch {
				nr++
				continue
			}
			if nr > 0 {
				tr += strconv.Itoa(nr) + string(ch)
			}
			ch = c
			nr = 1
		}
		r = tr + strconv.Itoa(nr) + string(ch)
	}

	return r
}
