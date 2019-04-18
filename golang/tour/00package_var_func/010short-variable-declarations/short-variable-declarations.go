package main

import "fmt"

// Every statement outside of function should start with keywords,
// so short variable declaration could not be used outside the function.

func main() {
	var i, j int = 1, 2
	k := 3
	c, python, java := true, false, "no!"
	fmt.Println(i, j, k, c, python, java)
}
