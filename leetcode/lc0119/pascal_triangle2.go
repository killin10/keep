// Package lc0119 solves leetcode problem 119 (Easy).
// https://leetcode.com/problems/pascals-triangle-ii/
package lc0119

func getRow(rowIndex int) []int {
	ans := make([]int, rowIndex+1)

	ans[0] = 1

	for i := 1; i <= rowIndex; i++ {
		ans[i] = 1
		for j := i - 1; j > 0; j-- {
			ans[j] = ans[j] + ans[j-1]
		}
	}

	return ans
}
