#include "sort.h"

/**
 * _swap - Swaps two nodes of a doubly linked list
 * @node: Node to be swapped
 * @list: The double linked list
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;

	if (!tmp->prev)
		*list = tmp->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;

	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                    order using the Cocktail shaker sort algorithm
 * @list: The head of the list to be sorted (Double Linked List)
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int swapped, n, m;

	if (!list || !(*list) || !((*list)->prev) || !((*list)->next))
		return;

	n = -1;
	m = -1;

	do {
		swapped = 0;
		n++;

		head = *list;
		while (head->next && n != m) {
			if (head->n > head->next->n) {
				aux = head;
				_swap(&aux, list);
				print_list(*list);
				head = aux;
				swapped = 1;
			}
			head = head->next;
		}

		if (n == 0)
			m = n;

		m--;

		while (head->prev && m <= n) {
			if (head->n < head->prev->n) {
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
				swapped = 1;
			}
			head = head->prev;
		}
	} while (swapped);
}
