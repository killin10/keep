// Package lc0028 solves leetcode problem 28 (Easy).
// https://leetcode.com/problems/implement-strstr/description/
package lc0028

// StrStr return the index of the first occurrence of needle in haystack.(Brute Force)
func StrStr(haystack string, needle string) int {
	h := []rune(haystack)
	n := []rune(needle)

	for i := 0; i <= len(h)-len(n); i++ {
		found := true
		for j := 0; j < len(n); j++ {
			if h[i+j] != n[j] {
				found = false
				break
			}
		}
		if found {
			return i
		}
	}

	return -1
}
