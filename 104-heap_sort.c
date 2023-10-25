#include "sort.h"

/**
 * check_tree - Sift down check
 * @array: Pointer to array
 * @size: Size of the pointer
 * @size_init: Original size of the array
 * @i: Index as a root of the tree
 */
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
	int root_val, left_val, right_val;
	size_t left_idx, right_idx;

	left_idx = i * 2 + 1;
	right_idx = left_idx + 1;
	left_val = array[left_idx];
	right_val = array[right_idx];

	if (((left_idx < size) && (right_idx < size) &&
		(left_val >= right_val && left_val > array[i])
		|| ((left_idx == size - 1) && left_val > array[i]))
	{
		root_val = array[i];
		array[i] = left_val;
		array[left_idx] = root_val;
		print_array(array, size_init);
	}
	else if ((left_idx < size) && (right_idx < size) &&
		(right_val > left_val && right_val > array[i]))
	{
		root_val = array[i];
		array[i] = right_val;
		array[right_idx] = root_val;
		print_array(array, size_init);
	}
	if (left_idx < size - 1)
		check_tree(array, size_init, size, left_idx);
	if (right_idx < size - 1)
		check_tree(array, size_init, size, right_idx);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Pointer to array
 * @size: Size of the pointer
 */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int temp;

	if (!array)
		return;
	for (i = 0; i < size / 2; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}
}
