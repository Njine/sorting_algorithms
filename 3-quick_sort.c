#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *      Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size) {
  /** Check if the array is null or empty. */
  if (array == NULL || size < 2) {
    return;
  }

  quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursive helper function for quick_sort
 *
 * @array: array to sort
 * @lo: lower index of partition to sort
 * @hi: upper index of partition to sort
 * @size: size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size) {
  /** Check if the partition is empty. */
  if (lo < hi) {
    int p = partition(array, lo, hi, size);
    quick_sort_helper(array, lo, p - 1, size);
    quick_sort_helper(array, p + 1, hi, size);
  }
}

/**
 * partition - partitions an array of integers using the Lomuto scheme
 *
 * @array: array to partition
 * @lo: lower index of partition to sort
 * @hi: upper index of partition to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size) {
  /** Get the pivot element. */
  int pivot = array[hi];

  /** Initialize the index of the smaller element. */
  int i = lo - 1;

  /** Iterate over the partition. */
  for (int j = lo; j <= hi - 1; j++) {
    /** If the current element is smaller than or equal to the pivot, swap it with the smaller element. */
    if (array[j] <= pivot) {
      i++;
      int tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      print_array(array, size);
    }
  }

  /** If the pivot element is not at the correct position, swap it with the smaller element. */
  if (i + 1 != hi) {
    int tmp = array[i + 1];
    array[i + 1] = array[hi];
    array[hi] = tmp;
    print_array(array, size);
  }

  /** Return the index of the pivot element. */
  return i + 1;
}
