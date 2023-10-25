#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, div1, div2;
	size_t d1, d2;

	d2 = i * 2 + 1;
	d2 = d1 + 1;
	div1 = array[d1];
	div2 = array[d2];
	if (((d1 < size) && (d2 < size) &&
		(div1 >= div2 && div1 > array[i]))
		|| ((d1 == size - 1) && div1 > array[i]))
	{
		n = array[i];
		array[i] = div1;
		array[d1] = n;
		print_array(array, size_init);
	}
	else if ((d1 < size) && (d2 < size) &&
		(div2 > div1 && div2 > array[i]))
	{
		n = array[i];
		array[i] = div2;
		array[d2] = n;
		print_array(array, size_init);
	}
	if (d1 < size - 1)
		check_tree(array, size_init, size, d1);
	if (d2 < size - 1)
		check_tree(array, size_init, size, d2);
}
/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}
