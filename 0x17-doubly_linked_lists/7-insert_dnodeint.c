#include "lists.h"

/**
* insert_dnodeint_at_index - USED TO INSERT A NODE AT A
*  - PARTICULAR POSITION
* @h: HEAD OF LIST
* @idx: INDEX OF NEW NODE.
* @n: VALUE OF NEW NODE.
* Return: ADDRESS OF NEW NODE, OTHERWISE NULL.
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int k;
	dlistint_t *HEAD;
	dlistint_t *NEW;

	NEW = NULL;
	if (idx == 0)
		NEW = add_dnodeint(h, n);
	else
	{
		HEAD = *h;
		k = 1;
		if (HEAD != NULL)
			while (HEAD->prev != NULL)
				HEAD = HEAD->prev;
		while (HEAD != NULL)
		{
			if (k == idx)
			{
				if (HEAD->next == NULL)
					NEW = add_dnodeint_end(h, n);
				else
				{
					NEW = malloc(sizeof(dlistint_t));

					if (NEW != NULL)
					{
						NEW->n = n;
						NEW->next = HEAD->next;
						NEW->prev = HEAD;
						HEAD->next->prev = NEW;
						HEAD->next = NEW;
					}
				}
				break;
			}

			HEAD = HEAD->next;
			k++;
		}
	}
return (NEW); }
