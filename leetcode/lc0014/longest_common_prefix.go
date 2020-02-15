// Package lc0014 solves leetcode problem 14 (Easy).
// https://leetcode.com/problems/longest-common-prefix/description/
package lc0014

import (
	"math"
	"strings"
)

// LongestCommonPrefix find the longest common prefix string amongst an array of strings.
// Vertical Scanning
func LongestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	runesArr := buildRunesArray(strs)

	for i := 0; i < len(runesArr[0]); i++ {
		current := runesArr[0][i]
		for j := 1; j < len(runesArr); j++ {
			if i >= len(runesArr[j]) || current != runesArr[j][i] {
				return string(runesArr[0][:i])
			}
		}
	}
	return string(runesArr[0])
}

// LongestCommonPrefixWithHorizontalScanning find the LCP using horizontal scanning.
// LCP(S1...Sn) = LCP(LCP(LCP(S1, S2), S3), ...Sn)
func LongestCommonPrefixWithHorizontalScanning(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	prefix := strs[0]
	for i := 0; i < len(strs); i++ {
		for len(prefix) > 0 && strings.Index(strs[i], prefix) != 0 {
			prefix = prefix[:len(prefix)-1]
		}
		if prefix == "" {
			return ""
		}
	}
	return prefix
}

// LCPWithDivideAndConquer find the LCP using Divide And Conquer.
// LCP(S1...Sn) = LCP(LCP(S1...Sk), LCP(S(k+1)...Sn))
func LCPWithDivideAndConquer(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	return lcpWithDivideAndConquer(strs, 0, len(strs)-1)
}

func lcpWithDivideAndConquer(strs []string, l int, r int) string {
	if l == r {
		return strs[l]
	}

	mid := (l + r) / 2
	return commonPrefix(lcpWithDivideAndConquer(strs, l, mid),
		lcpWithDivideAndConquer(strs, mid+1, r))
}

func commonPrefix(l string, r string) string {
	min := int(math.Min(float64(len(l)), float64(len(r))))
	if min == 0 {
		return ""
	}

	lr := []rune(l)
	rr := []rune(r)

	for i := 0; i < min; i++ {
		if lr[i] != rr[i] {
			return string(lr[:i])
		}
	}
	return string(lr[:min])
}

func buildRunesArray(strs []string) [][]rune {
	var runesArr [][]rune
	for _, v := range strs {
		runesArr = append(runesArr, []rune(v))
	}
	return runesArr
}
