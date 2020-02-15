package main

import "fmt"

// Vertex is ..
type Vertex struct {
	X int
	Y int
}

func main() {
	v := Vertex{1, 2}
	p := &v
	p.X = 1e9
	(*p).Y = 4
	fmt.Println(v)
}
