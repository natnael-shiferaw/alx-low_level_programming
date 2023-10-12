#include "lists.h"

/**
* delete_dnodeint_at_index - USED TO DELETE A NODE AT AN INDEX.
*
* @head: REPRESENTS HEAD OF NODE.
* @index: INDEX OF NEW NODE.
* Return: ON SUCCESS 1, -1 ON FAILURE.
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{

	unsigned int k;
	dlistint_t *H_1;
	dlistint_t *H_2;

	H_1 = *head;

	if (H_1 != NULL)
		while (H_1->prev != NULL)
			H_1 = H_1->prev;

	k = 0;

	while (H_1 != NULL)
	{
		if (k == index)
		{

			if (k == 0)
			{
				*head = H_1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				H_2->next = H_1->next;

				if (H_1->next != NULL)
					H_1->next->prev = H_2;
			}

			free(H_1);
			return (1);
		}
		H_2 = H_1;
		H_1 = H_1->next;
		k++;
	}
return (-1); }
