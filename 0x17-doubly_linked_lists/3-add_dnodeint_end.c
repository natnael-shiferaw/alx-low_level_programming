#include "lists.h"

/**
* add_dnodeint_end - A FUCNTION THAT ADD A NODE AT
* - THE END OF A dlistint_t LIST
* @head: REPRESENTS HEAD OF A NODE
* @n: REPRESENTS VALUE OF ELEMENT
* Return: RETURNS ADDRESS OF NEW ELEMENT
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{

	dlistint_t *NEW;
	dlistint_t *K;

	NEW = malloc(sizeof(dlistint_t));
	if (NEW == NULL)
		return (NULL);

	NEW->n = n;
	NEW->next = NULL;

	K = *head;

	if (K != NULL)
	{
		while (K->next != NULL)
			K = K->next;
		K->next = NEW;
	}
	else
	{
		*head = NEW;
	}

	NEW->prev = K;

	return (NEW);
}
