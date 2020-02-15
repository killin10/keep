package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (rot13 *rot13Reader) Read(b []byte) (int, error) {
	n, err := rot13.r.Read(b)
	for i := range b {
		c := b[i]

		if c >= 'a' && c <= 'z' {
			b[i] = c + 13
			if b[i] > 'z' {
				b[i] = 'a' + b[i] - 'z' - 1
			}
		} else if c >= 'A' && c <= 'Z' {
			b[i] = c + 13
			if b[i] > 'Z' {
				b[i] = 'A' + b[i] - 'Z' - 1
			}
		}
	}
	return n, err
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
