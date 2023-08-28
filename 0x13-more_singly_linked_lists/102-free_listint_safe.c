#include "lists.h"

/**
* free_listint_safe - used to free a linked list
* @h: a pointer for first node in the linked list
*
* Return: returns Number of Elements in the freed list.
*/
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int Diff;
	listint_t *Temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		Diff = *h - (*h)->next;
		if (Diff > 0)
		{
			Temp = (*h)->next;
			free(*h);
			*h = Temp;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}
