#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
* looped_listint_len - Count number of nodes that are unique
* in a looped listint_t linked list.
* @head: a pointer for the head of the listint_t used to check.
*
* Return: if the list is not looped - 0.
*        Otherwise - number of unique nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *Tortoise, *Hare;
	size_t Nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	Tortoise = head->next;
	Hare = (head->next)->next;

	while (Hare)
	{
		if (Tortoise == Hare)
		{
			Tortoise = head;
			while (Tortoise != Hare)
			{
				Nodes++;
				Tortoise = Tortoise->next;
				Hare = Hare->next;
			}

			Tortoise = Tortoise->next;
			while (Tortoise != Hare)
			{
				Nodes++;
				Tortoise = Tortoise->next;
			}

			return (Nodes);
		}

		Tortoise = Tortoise->next;
		Hare = (Hare->next)->next;
	}

	return (0);
}

/**
* print_listint_safe - used to Print/display a safe listint_t list.
* @head: a pointer for the head of the listint_t list
*
* Return:number of Nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t Nodes, i = 0;

	Nodes = looped_listint_len(head);

	if (Nodes == 0)
	{
		for (; head != NULL; Nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (i = 0; i < Nodes; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (Nodes);
}
