#include "search_algos.h"

/**
 * linear_search - A fucntion that searches for a value in a
 *                 linear form.
 * @array: represents an array of integers
 * @size: represents the size of the array
 * @value: represents the value to be searched.
 * Return: on success - index of value
 *         on failure(if not found) -  -1
 */

int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);
	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, *array);
		if (*array == value)
			return (i);
		array++;
	}
	return (-1);
}
