#include "lists.h"

/**
* get_dnodeint_at_index - A FUCNTION USED TO RETURN THE nth
*   - NODE AT THE INDEX
* @head: A POINTER TO HEAD OF NODE
* @index: INDEX OF NODE
* Return: ON SUCCESS nth NODE, NULL OTHERWISE.
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{

	dlistint_t *TEMP;
	unsigned int SIZE;

	SIZE = 0;
	if (head == NULL)
		return (NULL);

	TEMP = head;

	while (TEMP)
	{
		if (index == SIZE)
			return (TEMP);
		SIZE++;
		TEMP = TEMP->next;
	}

	return (NULL);
}
