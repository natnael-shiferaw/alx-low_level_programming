#include "lists.h"

/**
* pop_listint - used to delete the head node of a linked list
* @head: a pointer for the first element in the linked list
*
* Return: deleted data inside the elements, 0 if empty
*/
int pop_listint(listint_t **head)
{
	listint_t *Temp;
	int number;

	if (!head || !*head)
		return (0);

	number = (*head)->n;
	Temp = (*head)->next;
	free(*head);
	*head = Temp;

	return (number);
}
