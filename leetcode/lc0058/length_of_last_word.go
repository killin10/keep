// Package lc0058 solves leetcode problem 58 (Easy).
// https://leetcode.com/problems/length-of-last-word/description/
package lc0058

// LengthOfLastWord count length of the last word in a given string.
func LengthOfLastWord(s string) int {
	preCnt, cnt := 0, 0
	for _, v := range s {
		if v == ' ' {
			if cnt != 0 {
				preCnt, cnt = cnt, 0
			}
		} else {
			cnt++
		}
	}

	if cnt == 0 {
		return preCnt
	}
	return cnt
}
