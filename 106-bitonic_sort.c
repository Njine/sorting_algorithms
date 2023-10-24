#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers in the array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Merges bitonic sequences
 * @array: Array to be sorted
 * @size: Size of the array
 * @start: Starting index of the sequence
 * @seq: Length of the sequence
 * @ascending: 1 for ascending order, 0 for descending order
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char ascending)
{
    size_t i, j;
    int temp;

    if (seq <= 1)
        return;

    i = start;
    j = start + seq / 2;

    if (ascending)
        printf("Merging [%lu/%lu] (UP):\n", seq, size);
    else
        printf("Merging [%lu/%lu] (DOWN):\n", seq, size);
    print_array(&array[i], seq);

    for (size_t k = start; k < start + seq - 1; k++)
    {
        if (ascending == (array[k] > array[k + 1]))
        {
            swap_ints(&array[k], &array[k + 1]);
        }
    }

    bitonic_merge(array, size, start, seq / 2, ascending);
    bitonic_merge(array, size, start + seq / 2, seq / 2, ascending);

    if (ascending)
        printf("Result [%lu/%lu] (UP):\n", seq, size);
    else
        printf("Result [%lu/%lu] (DOWN):\n", seq, size);
    print_array(&array[start], seq);
}

/**
 * bitonic_sequence - Recursively creates bitonic sequences
 * @array: Array to be sorted
 * @size: Size of the array
 * @start: Starting index of the sequence
 * @seq: Length of the sequence
 * @ascending: 1 for ascending order, 0 for descending order
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char ascending)
{
    if (seq <= 1)
        return;

    if (ascending)
        printf("Merging [%lu/%lu] (UP):\n", seq, size);
    else
        printf("Merging [%lu/%lu] (DOWN):\n", seq, size);
    print_array(&array[start], seq);

    for (size_t k = start + seq / 2; k < start + seq; k++)
    {
        if (ascending == (array[k] > array[k - seq / 2]))
        {
            swap_ints(&array[k], &array[k - seq / 2]);
        }
    }

    bitonic_sequence(array, size, start, seq / 2, 1);
    bitonic_sequence(array, size, start + seq / 2, seq / 2, 0);

    if (ascending)
        printf("Result [%lu/%lu] (UP):\n", seq, size);
    else
        printf("Result [%lu/%lu] (DOWN):\n", seq, size);
    print_array(&array[start], seq);
}

/**
 * bitonic_sort - Sorts an array using the Bitonic Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    for (size_t seq = 2; seq <= size; seq *= 2)
    {
        for (size_t start = 0; start < size; start += seq)
        {
            char ascending = (start / seq) % 2 == 0 ? 1 : 0;
            bitonic_sequence(array, size, start, seq, ascending);
        }
    }
}
