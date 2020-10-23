/*
QUICK SORT ALGORITHM : 	TIME COMPLEXITY O(nlogn(n))

*/

#include <iostream>
using namespace std;

// note: call by address in swap function
void swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

// partition function which makes partition in array and return the partition
// index
int partition(int a[], int low, int high) {
  // i is leftmost index and j is the rightmost index
  int i = low, j = high;
  int pivot = a[low];

  do {
    do {
      i++;
    } while (
        a[i] <=
        pivot); // note :condition is for continuation of loop ans not for stop

    do {
      j--;
    } while (
        a[j] >
        pivot); // note: condition is for continuation of loop and not for stop

    if (i < j)            // note: condition
      swap(&a[i], &a[j]); // note:

  } while (i < j); // note:condition

  swap(&a[low], &a[j]); // note:

  return j;
}

// Quick sort function
void Quick_sort(int a[], int low, int high) {
  int j; // j is partition index

  // note: This condition for says that min two elements are required for quick
  // sort
  if (low < high) {
    // index j is partition index
    j = partition(a, low, high);

    // left partition  // note: low to j is for left partition
    Quick_sort(a, low, j);

    // right partition    //note: j+1 to high is for right partition
    Quick_sort(a, j + 1, high);
  }
}

// main function
int main() {

  int n;

  // n - number of inputs
  cin >> n;

  int arr[n];

  // input the custom array
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Before Quick Sort array is : ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Quick sort
  Quick_sort(arr, 0, n);

  cout << "After Quick Sort array is : ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
