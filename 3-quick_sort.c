#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *		Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursive helper function for quick_sort
 * @array: array to sort
 * @lo: lower index of partition to sort
 * @hi: upper index of partition to sort
 * @size: size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * partition - partitions an array of integers using the Lomuto scheme
 * @array: array to partition
 * @lo: lower index of partition to sort
 * @hi: upper index of partition to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != hi)
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
