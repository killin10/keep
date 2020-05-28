/*
 * @lc app=leetcode id=88 lang=golang
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (38.82%)
 * Likes:    2027
 * Dislikes: 3967
 * Total Accepted:    559.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 */

// @lc code=start
// package leetcode

func merge(nums1 []int, m int, nums2 []int, n int) {
	left, right, store := m-1, n-1, m+n-1

	for left >= 0 && right >= 0 {
		if nums1[left] >= nums2[right] {
			nums1[store] = nums1[left]
			left--
		} else {
			nums1[store] = nums2[right]
			right--
		}
		store--
	}

	for left >= 0 {
		nums1[store] = nums1[left]
		left--
		store--
	}

	for right >= 0 {
		nums1[store] = nums2[right]
		right--
		store--
	}
}

// @lc code=end
