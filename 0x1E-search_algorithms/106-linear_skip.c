#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted singly
 *   linked list using the Linear skip algorithm.
 * @list: pointer to the head of the linked list to search
 * @value: the value to search for
 * Return: on success - a pointer to the first node where
 *                      the value is found
 *         on failure -  NULL
 *	       (if the value is not present or
 *          the head of the list is NULL.)
 *
 * Description:
 *
 * Performs a search for a specified value within a sorted
 * singly linked list using the Linear Skip algorithm. It iterates
 * through the list, jumping in intervals based on the square root
 * of the list size until finding a range where the value might reside.
 * This range is further traversed linearly to pinpoint the exact
 * location of the value. Throughout the process, it prints the
 * values and indices of the nodes checked.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *jump_node;

	if (list == NULL)
		return (NULL);

	for (current = jump_node = list; jump_node->next != NULL && jump_node->n < value;)
	{
		current = jump_node;
		if (jump_node->express != NULL)
		{
			jump_node = jump_node->express;
			printf("Value checked at index [%ld] = [%d]\n",
				   jump_node->index, jump_node->n);
		}
		else
		{
			while (jump_node->next != NULL)
				jump_node = jump_node->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		   current->index, jump_node->index);

	for (; current->index < jump_node->index && current->n < value; current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	return (current->n == value ? current : NULL);
}
