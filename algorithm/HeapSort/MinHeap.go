package main

import (
	"fmt"
)

func build(a []int) {
	n := len(a)
	for i:=n/2-1; i>=0; i-- {
		down(a, i)
	}
}

func down(a []int, i int) bool {
	var k int
	j := i
	n := len(a)
	if n == 0 {
		return false
	}
	for {
		l := 2 * j + 1
		r := 2 * j + 2
		k = l
		if l >= n || l < 0 {      // l < 0 after int overflow
			break
		}
		if r < n && a[r] < a[l] {
			k = r
		}

		if a[k] >= a[j] {
			break
		}

		a[k], a[j] = a[j], a[k]
		j = k
	}

	return j > i
}

func up(a []int, j int) {
	for {
		i := (j - 1) / 2
		if i == j || a[i] <= a[j] {          // NOTE:
			break
		}
		a[i], a[j] = a[j], a[i]
		j = i
	}
}

func push(a []int, idx, val int) {
	a[idx] = val
	up(a, len(a)-1)   // NOTE:
}

func pop(a *[]int) int {
	r := (*a)[0]
	(*a)[0] = (*a)[len(*a)-1]
	*a = (*a)[:len(*a)-1]    // NOTE:
	down(*a, 0)            // NOTE:

	return r
}

func main() {
	a := []int{1, 2, 3, 8, 7, 6, 5, 4, 9, 10, 12, 11}

	build(a)
	
	for len(a) > 0 {
		x := pop(&a)
		fmt.Println(x)
	}

}