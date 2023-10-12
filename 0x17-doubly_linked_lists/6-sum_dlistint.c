#include "lists.h"

/**
* sum_dlistint - USED TO RETURN THE SUM OF ALL THE DATA
*  - OF DOUBLY LINKED LISTS.
*
* @head: REPRESENTS HEAD OF NODE
* Return: RETURNS SUM OF DATA.
*/

int sum_dlistint(dlistint_t *head)
{

	int SUM;

	SUM = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			SUM += head->n;
			head = head->next;
		}
	}

	return (SUM);
}
