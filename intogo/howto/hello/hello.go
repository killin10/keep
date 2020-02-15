package main

import (
	"fmt"

	"github.com/google/go-cmp/cmp"
	"github.com/killin10/keep/intogo/howto/stringutil"
)

func main() {
	fmt.Println(stringutil.Reverse("!oG ,olleH"))
	fmt.Println(cmp.Diff("Hello World", "Hello Go"))
}
