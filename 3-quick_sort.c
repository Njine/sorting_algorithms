#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Recursive helper function for quick_sort
 * @array: Array to be sorted
 * @lo: Lower index of the partition to be sorted
 * @hi: Upper index of the partition to be sorted
 * @size: Size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	while (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		lo = p + 1;
	}
}

/**
 * partition - Partitions an array of integers using the Lomuto scheme
 * @array: Array to be partitioned
 * @lo: Lower index of the partition to be sorted
 * @hi: Upper index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j = lo;

	while (j <= hi - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		j++;
	}

	if (i + 1 != hi)
	{
		int tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}

	return i + 1;
}
