// Package lc1431_array solves leetcode problem 1431 (Easy).
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
package lc1431-array

func kidsWithCandies(candies []int, extraCandies int) []bool {
	max := 0
	for i := 0; i < len(candies); i++ {
		if candies[i] > max {
			max = candies[i]
		}
	}

	mayGeatest := make([]bool, len(candies))
	for i := 0; i < len(candies); i++ {
		if candies[i]+extraCandies >= max {
			mayGeatest[i] = true
		} else {
			mayGeatest[i] = false
		}
	}

	return mayGeatest
}
