// Package lc0067 solves leetcode problem 67 (Easy).
// https://leetcode.com/problems/plus-one/description/
package lc0067

// AddBinary adds 2 binary numbers(represented by string).
func AddBinary(a string, b string) string {
	la, lb := len(a), len(b)

	result := make([]byte, max(la, lb)+1)
	var overflow byte = '0'
	i := 1
	for ; la-i >= 0 && lb-i >= 0; i++ {
		overflow = doAdd([]byte{a[la-i], b[lb-i], overflow}, result, i)
	}

	if i > lb {
		for ; la-i >= 0; i++ {
			overflow = doAdd([]byte{a[la-i], overflow}, result, i)
		}
	}

	if i > la {
		for ; lb-i >= 0; i++ {
			overflow = doAdd([]byte{b[lb-i], overflow}, result, i)
		}
	}

	if overflow != '0' {
		result[0] = overflow
		return string(result)
	}
	return string(result[1:])
}

func doAdd(bits []byte, result []byte, i int) byte {
	var sum byte
	for _, v := range bits {
		sum += v - '0'
	}
	if sum >= 2 {
		result[len(result)-i] = sum%2 + '0'
		return 1 + '0'
	}
	result[len(result)-i] = sum + '0'
	return '0'
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
