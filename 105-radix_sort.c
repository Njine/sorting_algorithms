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
void csort2(int *array, int **buff, size_t size, int lsd)
{
    int digit, index, counter = 10;
    int count_dig[10] = {0};
    int next_index[10] = {0};

    for (size_t k = 0; k < size; k++)
    {
        digit = array[k];
        for (index = 0; index < lsd; index++)
        {
            if (index > 0)
                digit = digit / 10;
        }
        digit = digit % 10;
        buff[digit][next_index[digit]] = array[k];
        next_index[digit] += 1;
    }

    for (int m = 1; m < counter; m++)
    {
        count_dig[m] += count_dig[m - 1];
    }

    for (size_t k = size; k > 0; k--)
    {
        digit = array[k - 1];
        for (index = 0; index < lsd; index++)
        {
            if (index > 0)
                digit = digit / 10;
        }
        digit = digit % 10;
        array[--count_dig[digit]] = buff[digit][next_index[digit] - 1];
        next_index[digit] -= 1;
    }

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
void csort(int *array, size_t size, int lsd)
{
    int count_dig[10] = {0};
    int digit, index, counter = 10;
    int **buff = malloc(sizeof(int *) * 10);

    if (!buff)
        return;

    for (size_t k = 0; k < size; k++)
    {
        digit = array[k];
        for (index = 0; index < lsd; index++)
        {
            if (index > 0)
                digit = digit / 10;
        }
        digit = digit % 10;
        count_dig[digit] += 1;
    }

    if (count_dig[0] == size)
    {
        free(buff);
        return;
    }

    for (int m = 0; m < counter; m++)
    {
        if (count_dig[m] != 0)
            buff[m] = malloc(sizeof(int) * count_dig[m]);
        else
            buff[m] = NULL;
    }

    csort2(array, buff, size, lsd);

    for (int m = 0; m < counter; m++)
    {
        if (count_dig[m] > 0)
            free(buff[m]);
    }
    free(buff);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix sort algorithm
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
