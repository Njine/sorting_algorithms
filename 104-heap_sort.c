#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Repair the heap whose exponent element is at index 'start'
 * @array: Array to sort.
 * @start: Index of the exponent element.
 * @end: Index of the end element.
 * @size: Size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t exponent = start;

    while (2 * exponent + 1 <= end)
    {
        size_t new = 2 * exponent + 1;
        size_t swap = exponent;

        if (array[swap] < array[new])
            swap = new;
        if (new + 1 <= end && array[swap] < array[new + 1])
            swap = new + 1;
        if (swap != exponent)
        {
            int filler = array[exponent];
            array[exponent] = array[swap];
            array[swap] = filler;
            print_array(array, size);
            exponent = swap;
        }
        else
        {
            break;
        }
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (int start = (size - 2) / 2; start >= 0; start--)
    {
        sift_down(array, start, size - 1, size);
    }

    for (int end = size - 1; end > 0; end--)
    {
        int filler = array[0];
        array[0] = array[end];
        array[end] = filler;
        print_array(array, size);
        sift_down(array, 0, end - 1, size);
    }
}
