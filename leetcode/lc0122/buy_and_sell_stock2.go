// Package lc0122 solves leetcode problem 122 (Easy).
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
package lc0122

import "math"

func maxProfit(prices []int) int {
	maxProfit := 0

	for i := 1; i < len(prices); i++ {
		if prices[i] > prices[i-1] {
			maxProfit += prices[i] - prices[i-1]
		}
	}
	return maxProfit
}

// naive approach
func maxProfitNaive(prices []int) int {
	totalProfit, profit, buy := 0, 0, math.MaxInt64

	for i := 0; i < len(prices); i++ {
		today := prices[i]

		if buy > today {
			buy = today
		}
		if today-buy > profit {
			profit = today - buy
		} else {
			buy = today
			totalProfit += profit
			profit = 0
		}
	}

	if profit != 0 {
		totalProfit += profit
	}

	return totalProfit
}
