/*
RADIX SORT ALGORITHM : TIME COMPLEXITY : O(nlog(n))
*/

#include <iostream>
using namespace std;

// function to get the max value from array elements
int getMax(int arr[], int n) {
  // mx stores the max elements of all the array elements
  int mx = arr[0];

  for (int i = 1; i < n; i++) {

    if (arr[i] > mx)
      mx = arr[i];
  }

  return mx;
}

// print function to print the array
void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

// countSort Implementing
void countSort(int arr[], int n, int exp) {
  // output array stores the required sorted array
  int output[n];
  int i, count[10] = {0};

  // Storing the count of occurrences of each element digits in count[]  array
  for (i = 0; i < n; i++) {
    // here counting digits if each elements
    count[(arr[i] / exp) % 10]++;
  }

  // Change count[i] so that count[i] now contains actual
  //  position of this digit in output[]
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // output array building
  for (i = n - 1; i >= 0; i--) {

    // here counting each digits of the array elements
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // array now contains sorted numbers according to current digit
  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

// Raix sort function
void radix_sort(int arr[], int n) {
  // here m stores the maximum element of the array
  int m = getMax(arr, n);

  // if m = 3 then exp values are 1 so elements are sorted on basis of unit
  // place digits if m = 32 then exp values are 1, 10 so elements are sorted on
  // basis of unit and tens place digits if m = 329 then exp values are 1, 10,
  // 100	so elements are sorted on basis of unit, tens and hundreds  place digits
  // if m = 3299 then exp values are 1, 10, 100, 1000 so elments are sorted on
  // basis of unit, tens , hundreds  and thousands place digits

  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}

// main function
int main() {
  // N - number of elements
  int N;

  // input array size
  cin >> N;

  int arr[N];

  for (int i = 0; i < N; i++) {
    // input array elements
    cin >> arr[i];
  }

  // calling radix sort function
  radix_sort(arr, N);

  // printing the sorted array
  cout << "The sorted array is : ";

  print(arr, N);
}
