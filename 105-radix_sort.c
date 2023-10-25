#include <stdlib.h>
#include "sort.h"

/**
 * csort2 - Auxiliary function of radix sort for sorting by LSD (Least
 *          Significant Digit).
 *
 * @array: Array of data to be sorted
 * @buff: Malloc buffer
 * @size: Size of the data
 * @lsd: The LSD position to consider during sorting
 *
 * Return: No return
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int i, j, sizec = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
		{
			if (j > 0)
				num = num / 10;
		}
		num = num % 10;
		buff[num][carr[num]] = array[i];
		carr[num] += 1;
	}

	for (i = 0, j = 0; i < sizec; i++)
	{
		while (carr[i] > 0)
		{
			array[j] = buff[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}

/**
 * csort - Auxiliary function of radix sort.
 *
 * @array: Array of data to be sorted
 * @size: Size of data
 * @lsd: The digit position being considered
 *
 * Return: No return
 */
void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, sizec = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
		{
			if (j > 0)
				num = num / 10;
		}
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < sizec; i++)
	{
		if (carr[i] != 0)
		{
			buff[i] = malloc(sizeof(int) * carr[i]);
		}
	}

	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < sizec; i++)
	{
		if (carr[i] > 0)
		{
			free(buff[i]);
		}
	}
	free(buff);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix
 *              sort algorithm.
 *
 * @array: Array of data to be sorted
 * @size: Size of data
 *
 * Return: No return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
