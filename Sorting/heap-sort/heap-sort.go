package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

type maxHeap struct {
	slice    []int
	heapSize int
}

func buildMaxHeap(slice []int) maxHeap {
	h := maxHeap{slice: slice, heapSize: len(slice)}
	for i := len(slice) / 2; i >= 0; i-- {
		h.MaxHeapify(i)
	}
	return h
}

func (h maxHeap) MaxHeapify(i int) {
	l, r := 2*i+1, 2*i+2
	max := i

	if l < h.size() && h.slice[l] > h.slice[max] {
		max = l
	}
	if r < h.size() && h.slice[r] > h.slice[max] {
		max = r
	}
	if max != i {
		h.slice[i], h.slice[max] = h.slice[max], h.slice[i]
		h.MaxHeapify(max)
	}
}

func (h maxHeap) size() int { return h.heapSize }

func heapSort(n int, slice []int) []int {
	h := buildMaxHeap(slice)
	for i := n - 1; i >= 1; i-- {
		h.slice[0], h.slice[i] = h.slice[i], h.slice[0]
		h.heapSize--
		h.MaxHeapify(0)
	}
	return h.slice
}

func readArray(reader *bufio.Reader, n int) []int {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}

	temp := strings.Split(string(str), " ")
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		arr[i], err = strconv.Atoi(temp[i])
		if err != nil {
			panic(err)
		}
	}

	return arr
}

func main() {
	defer writer.Flush()

	var n int
	_, _ = fmt.Fscanf(reader, "%d\n", &n)
	arr := readArray(reader, n)

	fmt.Println("Before:", arr)
	heapSort(n, arr)
	fmt.Println("After:", arr)
}
