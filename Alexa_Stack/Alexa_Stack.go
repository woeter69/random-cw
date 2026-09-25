package main

import "fmt"

func twoStacks(maxSum int32, a []int32, b []int32) int32 {
	var count, sum int32
	var i, j int

	for i < len(a) && sum+a[i] <= maxSum {
		sum += a[i]
		i++
	}
	count = int32(i)

	for j < len(b) {
		sum += b[j]
		j++

		for sum > maxSum && i > 0 {
			i--
			sum -= a[i]
		}

		if sum <= maxSum {
			if int32(i+j) > count {
				count = int32(i + j)
			}
		} else {
			break
		}
	}

	return count
}

func main() {
	maxSum := int32(10)
	a := []int32{4, 2, 4, 6, 1}
	b := []int32{2, 1, 8, 5}

	fmt.Printf("Count: %d\n", twoStacks(maxSum, a, b))
}
