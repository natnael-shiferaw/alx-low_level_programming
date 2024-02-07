#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted singly linked list
 *             using the Jump search algorithm.
 * @list: pointer to the head of the linked list to search.
 * @size: represents the number of nodes in the list.
 * @value: represents the value to be searched.
 *
 * Return: on success - a pointer to the first node where
 *                      the value is found
 *         on failure -  NULL
 *	       (if the value is not present or
 *          the head of the list is NULL.)
 * Description:
 *
 * Prints a value every time it is compared in the list.
 * Uses the square root of the list size as the jump step.
 * The function initializes variables for step, step size,
 *  and two pointers:
 * one for traversing and one for jumping. It iterates through
 * the list, jumping at step intervals until the value is found
 * or the end of the list is reached. Prints values checked during
 * the search. Then iterates through the potential range and
 * prints values for debugging. Returns the node if found,
 *  otherwise NULL.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t jump_step, step_size;
listint_t *current_node, *jump_node;

if (list == NULL || size == 0)
	return (NULL);

jump_step = 0;
step_size = sqrt(size);

for (current_node = jump_node = list;
jump_node->index + 1 < size && jump_node->n < value;)
{
current_node = jump_node;

for (jump_step += step_size; jump_node->index < jump_step;
jump_node = jump_node->next)
{
	if (jump_node->index + 1 == size)
			break;
}
printf("Value checked at index [%ld] = [%d]\n", jump_node->index,
		jump_node->n);
}

printf("Value found between indexes [%ld] and [%ld]\n",
		current_node->index, jump_node->index);

for (; current_node->index < jump_node->index && current_node->n < value;
current_node = current_node->next)
	printf("Value checked at index [%ld] = [%d]\n",
		current_node->index, current_node->n);
printf("Value checked at index [%ld] = [%d]\n", current_node->index,
	current_node->n);

return (current_node->n == value ? current_node : NULL);
}
