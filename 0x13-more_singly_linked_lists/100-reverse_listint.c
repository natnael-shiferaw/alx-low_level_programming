#include "lists.h"

/**
* reverse_listint - used to reverse a linked list
* @head: a pointer for the first node in the list
*
* Return: a pointer to the first node in the new list
*/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *before = NULL;
	listint_t *after = NULL;

	while (*head)
	{
		after = (*head)->after;
		(*head)->after = before;
		before = *head;
		*head = after;
	}

	*head = before;

	return (*head);
}