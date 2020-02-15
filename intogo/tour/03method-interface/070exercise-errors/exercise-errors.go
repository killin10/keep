package main

import (
	"fmt"
	"math"
)

// ErrNegativeSqrt is ..
type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, ErrNegativeSqrt(-2)
	}

	z := 1.0
	lastZ := 0.0

	for math.Abs(z-lastZ) > 0.0000001 {
		lastZ = z
		z -= (z*z - x) / (2 * z)
		fmt.Println(lastZ)
		fmt.Println(z)
	}

	return z, nil
}

func main() {
	fmt.Println(sqrt(2))
	fmt.Println(sqrt(-2))
}
