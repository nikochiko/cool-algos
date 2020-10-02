package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func bubbleSort(n int, arr []int) {
  // O(n^2)
  // Sort in ascending order
  for j := 0; j < n; j++ {
    for i := 0; i < n - j - 1; i++ {
      if arr[i] > arr[i+1] {
        arr[i], arr[i+1] = arr[i+1], arr[i]
      }
    }
  }
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
  fmt.Fscanf(reader, "%d\n", &n)
  arr := readArray(reader, n)

  fmt.Println("Before:", arr)
  bubbleSort(n, arr)
  fmt.Println("After:", arr)
}
