#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int *buffer, size_t min, size_t mid, size_t max);
void merge_sort_recursive(int *array, int *buffer, size_t min, size_t max);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    merge_sort_recursive(array, buffer, 0, size - 1);
    free(buffer);
}

/**
 * merge_sort_recursive - Recursively sorts the array using Merge sort.
 * @array: Array to be sorted.
 * @buffer: Temporary buffer for merging.
 * @min: Minimum index of the subarray.
 * @max: Maximum index of the subarray.
 */
void merge_sort_recursive(int *array, int *buffer, size_t min, size_t max)
{
    if (min < max)
    {
        size_t mid = min + (max - min) / 2;
        merge_sort_recursive(array, buffer, min, mid);
        merge_sort_recursive(array, buffer, mid + 1, max);
        merge(array, buffer, min, mid, max);
    }
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: Original array containing the subarrays.
 * @buffer: Temporary buffer for merging.
 * @min: Minimum index of the left subarray.
 * @mid: Maximum index of the left subarray.
 * @max: Maximum index of the right subarray.
 */
void merge(int *array, int *buffer, size_t min, size_t mid, size_t max)
{
    size_t i = min, j = mid + 1, k = min;

    printf("Merging...\n");
    printf("[left]: ");
    for (size_t l = min; l <= mid; l++)
    {
        printf("%d", array[l]);
        if (l < mid)
            printf(", ");
    }
    printf("\n");

    printf("[right]: ");
    for (size_t r = mid + 1; r <= max; r++)
    {
        printf("%d", array[r]);
        if (r < max)
            printf(", ");
    }
    printf("\n");

    while (i <= mid && j <= max)
    {
        if (buffer[i] <= buffer[j])
        {
            array[k] = buffer[i];
            i++;
        }
        else
        {
            array[k] = buffer[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        array[k] = buffer[i];
        i++;
        k++;
    }

    while (j <= max)
    {
        array[k] = buffer[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    for (size_t l = min; l <= max; l++)
    {
        printf("%d", array[l]);
        if (l < max)
            printf(", ");
    }
    printf("\n");
}
