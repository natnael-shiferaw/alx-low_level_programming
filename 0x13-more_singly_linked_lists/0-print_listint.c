#include "lists.h"

/**
* print_listint - it prints/displays elements for linked lists
* @h: it's a linked list to be printed of listint_t type
*
* Return: number of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t z = 0;

	while (h)
	{
		printf("%d\n", h->n);
		z++;
		h = h->next;
	}

	return (z);
}
