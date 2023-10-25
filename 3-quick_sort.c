#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Recursive helper function for quick_sort.
 * @array: Array to sort.
 * @lo: Lower index of partition to sort.
 * @hi: Upper index of partition to sort.
 * @size: Size of the array.
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int x;

	while (lo < hi)
	{
		x = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, x - 1, size);
		lo = x + 1;
	}
}

/**
 * partition - Partitions an array of integers using the Lomuto scheme.
 * @array: Array to partition.
 * @lo: Lower index of partition to sort.
 * @hi: Upper index of partition to sort.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int k, j, pivot, temp;

	pivot = array[hi];
	k = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			k++;
			if (k != j)
			{
				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (k + 1 != hi)
	{
		temp = array[k + 1];
		array[k + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (k + 1);
}
