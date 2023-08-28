#include "lists.h"

/**
* insert_nodeint_at_index -used for insertion of a new node in a linked list,
* for a given position
* @head: a pointer for the first node in the list
* @idx: an index where the new node is going to be added
* @n: data to be inserted in the new node
*
* Return: a pointer to the new node, or NULL
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *a;
	listint_t *Temp = *head;

	a = malloc(sizeof(listint_t));
	if (!a || !head)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (idx == 0)
	{
		a->next = *head;
		*head = a;
		return (a);
	}

	for (j = 0; Temp && j < idx; j++)
	{
		if (j == idx - 1)
		{
			a->next = Temp->next;
			Temp->next = a;
			return (a);
		}
		else
			Temp = Temp->next;
	}

	return (NULL);
}
