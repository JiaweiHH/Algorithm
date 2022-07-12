package main

import "fmt"

type A struct {
	val *int
}

type B struct {
	a A
}

// b ->(-1) ~ret
// b ->(-1) a, c ->(-1) a
// c ->(-1) a ->(1) a.val
func dummy() int {
	var b B
	a := &b.a
	c := 1
	a.val = &c
	return 1
}

// func dummy1() *int {
// 	var b int
// 	a := &b
// 	c := 1
// 	*a = c
// 	return &b
// }

func main() {
	// fmt.Println(dummy())
	
	fmt.Println(dummy())
	// fmt.Println(dummy1())
}
