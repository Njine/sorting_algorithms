#include "sort.h"

/* Function prototype for print_array */
void print_array(const int *array, size_t size);

/* Function prototype for hoare_partition */
int hoare_partition(int *array, int low, int high, size_t size);

/* Function prototype for qsh_helper */
void qsh_helper(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the Quick sort algorithm with the Hoare partition scheme.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    qsh_helper(array, 0, size - 1, size);
}

/**
 * qsh_helper - Recursive helper function for quick_sort_hoare.
 * @array: Array to be sorted.
 * @low: Lowest index of the partition to sort.
 * @high: Highest index of the partition to sort.
 * @size: Size of the array.
 */
void qsh_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);
        qsh_helper(array, low, pivot, size);
        qsh_helper(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions an array using the Hoare partition scheme.
 * @array: Array to partition.
 * @low: Lowest index of the partition to sort.
 * @high: Highest index of the partition to sort.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low];
    int left = low - 1;
    int right = high + 1;
    int tmp;

    while (1)
    {
        while (array[left] < pivot)
            left++;

        while (array[right] > pivot)
            right--;

        if (left >= right)
            return right;

        tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;
        print_array(array, size);
    }
}
