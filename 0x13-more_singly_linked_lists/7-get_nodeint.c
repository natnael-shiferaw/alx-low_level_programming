#include "lists.h"

/**
* get_nodeint_at_index - return the node at a particular index in a linked list
* @head: is the first node in the linked list
* @index: is the index of the node to Return
*
* Return: a pointer to the node, or NULL
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j = 0;
	listint_t *Temp = head;

	while (Temp && j < index)
	{
		Temp = Temp->next;
		j++;
	}

	return (Temp ? Temp : NULL);
}
