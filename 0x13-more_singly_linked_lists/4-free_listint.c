#include "lists.h"

/**
* free_listint - is used to free a linked list
* @head: a list to be freed that is type listint_t
*/
void free_listint(listint_t *head)
{
	listint_t *Temp;

	while (head)
	{
		Temp = head->next;
		free(head);
		head = Temp;
	}
}
