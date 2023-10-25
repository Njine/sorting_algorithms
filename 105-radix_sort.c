#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @buff: malloc buffer
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int i, j, sizey = 10, dig;
	int cr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int cr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	i = 0;
  do {
    dig = array[i];
    for (j = 0; j < lsd; j++) {
      if (j > 0) {
        dig = dig / 10;
      }
    }
    dig = dig % 10;
    cr[dig] += 1;
    i++;
  } while (i < size);

  i = 0;
  j = 0;
  do {
    while (cr[i] > 0) {
      array[j] = buff[i][cr2[i]];
      cr2[i] += 1;
      cr[i] -= 1;
      j++;
    }
    i++;
  } while (i < sizey);

  print_array(array, size);
}
/**
 * csort - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void csort(int *array, int size, int lsd)
{
	int cr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, dig, sizey = 10, **buff;

	for (i = 0; i < size; i++)
	{
		dig = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				dig = dig / 10;
		dig = dig % 10;
		cr[dig] += 1;
	}

	if (cr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < sizey; i++)
		if (cr[i] != 0)
			buff[i] = malloc(sizeof(int) * cr[i]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < sizey; i++)
		if (cr[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
