package main

import "fmt"

var (
	ival int
	fval float64
	sval string
)

func init() {
	ival, fval, sval = 2, 4.0, "string value"
}

func main() {
	fmt.Println(ival, fval, sval)
}
