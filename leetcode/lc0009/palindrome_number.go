// Package lc0009 solves leetcode problem 9 (Easy).
// https://leetcode.com/problems/palindrome-number/description/
package lc0009

// IsPalindrome tell whether a number is palindrome. We revert only half of the number.
func IsPalindrome(x int) bool {
	// x%10 == 0 这个前置判断，使得后面 x > revertedNr 和 x == revertedNr/10 的判断是成立的，比如 x = 100
	if x < 0 || (x != 0 && x%10 == 0) {
		return false
	}

	revertedNr := 0
	for x > revertedNr {
		revertedNr = revertedNr*10 + x%10
		x = x / 10
	}

	return x == revertedNr || x == revertedNr/10
}
