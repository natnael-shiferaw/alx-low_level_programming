#include "search_algos.h"

/**
 * jump_search - A function that is used to search for a
 *               value in a sorted array.
 * @array: pointer to the first element of the array
 * @size:  represents the size of the array.
 * @value: represents the value to be searched.
 * Return: returns the first index where value is found.
 *
 * Description:
 *
 * This function performs jump search on a sorted integer array.
 * It starts by checking if the array is NULL or empty, returning -1 if so.
 * Then, it sets the jump step as the square root of the array size,
 * initializes pointers, and moves the right pointer forward until
 * it finds a value greater than or equal to the target or reaches the end.
 * It prints the indices checked during this process.
 * After finding the appropriate range, it searches linearly for the value
 * and returns its index if found, otherwise prints a message and returns -1.
 */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
