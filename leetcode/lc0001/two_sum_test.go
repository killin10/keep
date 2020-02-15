package lc0001

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var nums = []int{2, 7, 11, 15}
var target = 9

func TestTwoSum(t *testing.T) {
	checkResult(TwoSum(nums, target), t)
}

func TestTwoSumWith2PassHashTable(t *testing.T) {
	checkResult(TwoSumWith2PassHashTable(nums, target), t)
}

func TestTwoSumWith1PassHashTable(t *testing.T) {
	checkResult(TwoSumWith1PassHashTable(nums, target), t)
}

func checkResult(actual []int, t *testing.T) {
	assert.Contains(t, [][]int{[]int{0, 1}, []int{1, 0}}, actual)
}
