/*
 * @lc app=leetcode id=11 lang=golang
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (49.91%)
 * Likes:    5646
 * Dislikes: 565
 * Total Accepted:    620.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
// package leetcode

func maxArea(height []int) int {
	volume := 0

	for left := 0; left < len(height)-1; left++ {
		for right := left + 1; right < len(height); right++ {
			v := min(height[left], height[right]) * (right - left)
			if v > volume {
				volume = v
			}
		}
	}

	return volume
}

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

// @lc code=end
