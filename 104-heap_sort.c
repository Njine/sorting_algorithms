#include "sort.h"

/**
 * sift_down - Sift down in a heap
 * @array: Pointer to the array
 * @size_init: Original size of the array
 * @size: Current size of the array
 * @root: Index of the root of the tree
 */
void sift_down(int *array, size_t size_init, size_t size, size_t root)
{
	int tmp, left, right;
	size_t child_left, child_right;

	child_left = root * 2 + 1;
	child_right = child_left + 1;
	left = array[child_left];
	right = array[child_right];

	if (child_left < size && (child_right >= size || left >= right))
	{
		tmp = array[root];
		array[root] = left;
		array[child_left] = tmp;
		print_array(array, size_init);
		sift_down(array, size_init, size, child_left);
	}
	else if (child_right < size && right > left)
	{
		tmp = array[root];
		array[root] = right;
		array[child_right] = tmp;
		print_array(array, size_init);
		sift_down(array, size_init, size, child_right);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int tmp;

	if (!array)
		return;
	for (i = size / 2; i > 0; i--)
		sift_down(array, size_init, size, i - 1);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size_init);
		sift_down(array, size_init, i, 0);
	}
}
