#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
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
 * merge - Merges two sorted sets of data in ascending order.
 *
 * @array: First set of data
 * @buff: Second set of data
 * @minFirst: Lower range of the first set of data
 * @maxFirst: Upper range of the first set of data
 * @minSecond: Lower range of the second set of data
 * @maxSecond: Upper range of the second set of data
 */
void merge(int *array, int *buff, int minFirst, int maxFirst, int minSecond, int maxSecond)
{
    int i = minFirst, j = minSecond, k = minFirst;

    while (i <= maxFirst || j <= maxSecond)
    {
        if (i <= maxFirst && j <= maxSecond)
        {
            if (buff[i] <= buff[j])
                array[k] = buff[i], k++, i++;
            else
                array[k] = buff[j], k++, j++;
        }
        else if (i > maxFirst && j <= maxSecond)
        {
            array[k] = buff[j], k++, j++;
        }
        else
        {
            array[k] = buff[i], k++, i++;
        }
    }
}
/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
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
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
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
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
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
