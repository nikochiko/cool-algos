import java.io.*;
import java.util.*;

public class Quick_Sort {
  public static void main(String[] args) {
    int[] arr = takeinput();

    // sort the array
    Quick_Sort(arr, 0, arr.length - 1);

    // display the array
    for (int i = 0; i < arr.length; i++)
      System.out.print(arr[i] + " ");
  }

  public static int[] takeinput() {
    Scanner scn = new Scanner(System.in);

    // input array length
    int n = scn.nextInt();

    int[] arr = new int[n];

    for (int i = 0; i < arr.length; i++) {
      // input array elements
      arr[i] = scn.nextInt();
    }

    return arr;
  }

  public static void Quick_Sort(int[] arr, int lo, int hi) {
    // if low index is higher than high index, simply return
    if (lo >= hi)
      return;

    // define pivot
    int pi = (lo + hi) / 2;
    int pivot = arr[pi];
    int left = lo, right = hi;

    while (left <= right) {
      while (arr[left] < pivot)
        left++;

      while (arr[right] > pivot)
        right--;

      if (left <= right) {
        // swap the values
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
      }
    }

    Quick_Sort(arr, lo, right);
    Quick_Sort(arr, left, hi);
  }
}
