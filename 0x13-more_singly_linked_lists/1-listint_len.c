#include "lists.h"

/**
* listint_len -function returns number of elements for the linked lists
* @h: represents a linked list to traverse that is type listint_t
*
* Return: the number of nodes
*/
size_t listint_len(const listint_t *h)
{
	size_t z = 0;

	while (h)
	{
		z++;
		h = h->next;
	}

	return (z);
}
