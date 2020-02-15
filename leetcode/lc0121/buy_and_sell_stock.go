// Package lc0121 solves leetcode problem 121 (Easy).
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
package lc0121

import "math"

func maxProfit(prices []int) int {
	profit, buy := 0, math.MaxInt64

	for i := 0; i < len(prices); i++ {
		today := prices[i]

		if buy > today {
			buy = today
		}
		if today-buy > profit {
			profit = today - buy
		}
	}

	return profit
}
