#include "lists.h"

/**
* dlistint_len - USED TO RETURN THE NUMBER OF ELEMENTS
*  - IN A DOUBLE LINKED LIST
* @h: REPRESENTS THE HEAD OF NODE
* Return: RETURNS NUMBER OF NODES.
*/

size_t dlistint_len(const dlistint_t *h)
{
	int COUNT;

	COUNT = 0;

	if (h == NULL)
		return (COUNT);


	while (h->prev != NULL)
		h = h->prev;


	while (h != NULL)
	{
		COUNT++;
		h = h->next;
	}

	return (COUNT);
}
