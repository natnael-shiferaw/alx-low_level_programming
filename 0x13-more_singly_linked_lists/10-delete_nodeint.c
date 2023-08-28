#include "lists.h"

/**
* delete_nodeint_at_index - it deletes a node at a particular
*                          index in a linked list
* @head: a pointer to the first element in the list
* @index: an index of the node to delete
*
* Return: 1 for Success, or -1 for Failure
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *Temp = *head;
	listint_t *Current = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(Temp);
		return (1);
	}

	while (j < index - 1)
	{
		if (!Temp || !(Temp->next))
			return (-1);
		Temp = Temp->next;
		j++;
	}


	Current = Temp->next;
	Temp->next = Current->next;
	free(Current);

	return (1);
}
