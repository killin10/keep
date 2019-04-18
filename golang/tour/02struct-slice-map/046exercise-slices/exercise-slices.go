package main

import "golang.org/x/tour/pic"

// Pic is ...
func Pic(dx, dy int) [][]uint8 {
	ys := make([][]uint8, dy)

	for y := 0; y < dy; y++ {
		ys[y] = make([]uint8, dx)
		for x := 0; x < dx; x++ {
			ys[y][x] = uint8(x * y)
		}
	}

	return ys
}

func main() {
	pic.Show(Pic)
}
