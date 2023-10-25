#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
* @list: A pointer to a doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_node;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;

while (current)
{
next_node = current->next;

while (current->prev != NULL && current->n < current->prev->n)
{
current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
current->next = current->prev;
current->prev = current->next->prev;
current->next->prev = current;

if (current->prev == NULL)
*list = current;
else
current->prev->next = current;

print_list(*list);
}

current = next_node;
}
}
