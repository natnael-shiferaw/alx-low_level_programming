#include "lists.h"

/**
* add_nodeint_end - at end of a linked list, it adds a node
* @head: is a pointer for the first element in the list
* @n: is data to inserted in the new element
*
* Return: returns pointer to the new node on success,NULL if it fails
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a;
	listint_t *temp = *head;

	a = malloc(sizeof(listint_t));
	if (!a)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (*head == NULL)
	{
		*head = a;
		return (a);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = a;

	return (a);
}
