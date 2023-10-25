#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - Copy data from one buffer to another
 * @src: Source buffer
 * @dst: Destination buffer
 * @size: Size of buffers
 *
 * Return: No Return
 */
void copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}

/**
 * merge - Merge two sets of data in ascending order (previously sorted)
 * @array: First set of data
 * @buff: Second set of data
 * @minL: Lower range of the first set of data
 * @maxL: Upper range of the first set of data
 * @minR: Lower range of the second set of data
 * @maxR: Upper range of the second set of data
 *
 * Return: No Return
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	for (; i <= maxL || j <= maxR;)
	{
		if (i <= maxL && j <= maxR)
		{
			if (buff[i] <= buff[j])
			{
				array[k] = buff[i];
				k++;
				i++;
			}
			else
			{
				array[k] = buff[j];
				k++;
				j++;
			}
		}
		else if (i > maxL && j <= maxR)
		{
			array[k] = buff[j];
			k++;
			j++;
		}
		else
		{
			array[k] = buff[i];
			k++;
			i++;
		}
	}
}

/**
 * printcheck - Print an array in a given range
 * @array: Array of data to be printed
 * @r1: Start of range
 * @r2: End of range
 *
 * Return: No Return
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split - Recursive function to split data into a merge tree
 * @array: Array of data to be split
 * @buff: Auxiliary array of data for merging
 * @min: Min range of data in the array
 * @max: Max range of data in the array
 * @size: Size of the total data
 *
 * Return: No Return
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");
	printcheck(array, minL, maxL);
	printf("[right]: ");
	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Array of data to be sorted
 * @size: Size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}
