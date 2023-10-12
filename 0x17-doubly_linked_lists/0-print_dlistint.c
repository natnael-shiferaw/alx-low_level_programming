#include "lists.h"

/**
* print_dlistint - USED TO PRINT ALL THE ELEMENTS
*  OF A dlistint_t LIST
* @h: REPRESENTS THE HEAD OF A LIST
* Return: RETURNS NUMBER OF NODES
*/

size_t print_dlistint(const dlistint_t *h)
{
	int COUNT;

	COUNT = 0;

	if (h == NULL)
		return (COUNT);


	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		COUNT++;
		h = h->next;
	}

	return (COUNT);
}
