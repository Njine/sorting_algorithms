#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print array */
void print_array(const int *array, size_t size);

/* Print linked list */
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void _swap_array(int *array, int i, int j);
void _swap(listint_t **node, listint_t **list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void copy(int *src, int *dst, int size);
void printcheck(int *array, int r1, int r2);
void split(int *array, int *buff, int min, int max, int size);
void heap_sort(int *array, size_t size);
void check_tree(int *array, size_t size_init, size_t size, size_t i);
void radix_sort(int *array, size_t size);
void csort2(int *array, int **buff, int size, int lsd);
void csort(int *array, int size, int lsd);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq,
		char flow);

#endif /* SORT_H */

