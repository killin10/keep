package main

import "fmt"

func typeAssert() {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("recover")
			fmt.Println(err)
		}
	}()

	var val interface{}
	val = 1
	str := val.(string)

	fmt.Println(str)
}

func main() {
	typeAssert()

	var val interface{}
	val = 1
	str, ok := val.(string)
	if ok {
		fmt.Printf("val is string, value is %v\n", str)
	} else {
		fmt.Printf("val is not string, value is %v\n", val)
	}
}
