#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using Selection Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
    size_t outer, inner;
    int temp;

    if (!array || size < 2)
        return;

    outer = 0;
    while (outer < size - 1)
    {
        inner = 0;
        while (inner < size - 1)
        {
            if (array[inner] > array[inner + 1])
            {
                temp = array[inner];
                array[inner] = array[inner + 1];
                array[inner + 1] = temp;
                print_array(array, size);
            }
            inner++;
        }
        outer++;
    }
}
