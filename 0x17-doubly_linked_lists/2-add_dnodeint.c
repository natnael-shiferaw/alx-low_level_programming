#include "lists.h"

/**
* add_dnodeint - A FUCNTION THAT IS USED TO ADD A
* -    NODE AT THE BEGGINING OF A dlistint_t LIST
* @head: REPRESENTS HEAD OF A LIST
* @n: REPRESENTS A VALUE OF ELEMENT
* Return: RETURNS THE ADDRESS OF THE NEW ELEMENT
*/


dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *K;
	dlistint_t *NEW;

	NEW = malloc(sizeof(dlistint_t));

	if (NEW == NULL)
		return (NULL);

	NEW->n = n;
	NEW->prev = NULL;
	K = *head;

	if (K != NULL)
	{
		while (K->prev != NULL)
			K = K->prev;
	}

	NEW->next = K;

	if (K != NULL)
		K->prev = NEW;

	*head = NEW;

	return (NEW);
}
