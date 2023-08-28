#include "lists.h"

/**
* find_listint_loop - used to find the loop in a linked list
* @head: is the linked list to search for
*
* Return: an address of the node where the loop is started,
*      or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *Slow = head;
	listint_t *Fast = head;

	if (!head)
		return (NULL);

	while (Slow && Fast && Fast->next)
	{
		Fast = Fast->next->next;
		Slow = Slow->next;
		if (Fast == Slow)
		{
			Slow = head;
			while (Slow != Fast)
			{
				Slow = Slow->next;
				Fast = Fast->next;
			}
			return (Fast);
		}
	}

	return (NULL);
}
