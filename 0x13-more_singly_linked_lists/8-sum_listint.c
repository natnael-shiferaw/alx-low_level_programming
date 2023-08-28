#include "lists.h"

/**
* sum_listint - computes sum of all the data in a listint_t list
* @head: is the first node in the linked list
*
* Return: the computed sum
*/
int sum_listint(listint_t *head)
{
	int SUM = 0;
	listint_t *Temp = head;

	while (Temp)
	{
		SUM += Temp->n;
		Temp = Temp->next;
	}

	return (SUM);
}
