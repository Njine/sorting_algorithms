#include <stdio.h>
#include "sort.h"

/* Function prototype for print_array */
void print_array(const int *array, size_t size);

/* Function prototype for lomuto_partition */
int lomuto_partition(int *array, int low, int high, size_t size);

/* Function prototype for qsh_helper */
void qsh_helper(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Lomuto partition scheme.
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    qsh_helper(array, 0, size - 1, size);
}

/**
 * qsh_helper - recursive helper function for quick_sort
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 */
void qsh_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        qsh_helper(array, low, pivot - 1, size);
        qsh_helper(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: array to partition
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;
    int tmp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            print_array(array, size);
        }
    }

    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    print_array(array, size);

    return (i + 1);
}
