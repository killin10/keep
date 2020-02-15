// Package lc0118 solves leetcode problem 118 (Easy).
// https://leetcode.com/problems/pascals-triangle/
package lc0118

func generate(numRows int) [][]int {
	ans := make([][]int, numRows)
	if numRows <= 0 {
		return ans
	}

	ans[0] = []int{1}

	for i := 1; i < numRows; i++ {
		lastRow := ans[i-1]
		row := make([]int, i+1)

		row[0] = 1
		row[i] = 1

		for j := 1; j < i; j++ {
			row[j] = lastRow[j-1] + lastRow[j]
		}

		ans[i] = row
	}
	return ans
}
