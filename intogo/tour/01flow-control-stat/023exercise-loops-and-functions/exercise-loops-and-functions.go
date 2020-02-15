package main

import (
	"fmt"
	"math"
)

func sqrt(x float64) float64 {
	z := 1.0
	lastZ := 0.0

	for math.Abs(z-lastZ) > 0.0000001 {
		lastZ = z
		z -= (z*z - x) / (2 * z)
		fmt.Println(lastZ)
		fmt.Println(z)
	}

	return z
}

func main() {
	fmt.Println(sqrt(2))
}
