#include "lists.h"

/**
* free_dlistint - USED TO FREE A dlistint_t LIST.
*
* @head: A POINTER TO HEAD OF NODE.
* Return: VOID - NOTHING.
*/

void free_dlistint(dlistint_t *head)
{

	if (head == NULL)
		return;

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
