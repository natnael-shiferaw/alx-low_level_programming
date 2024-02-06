#include "search_algos.h"

/**
 * binary_recursive - a function that recursively searches for
 *                    a value in a sorted array.
 * @array: pointer to the first element of the array
 * @left: starting index of the subarray
 * @right: ending index of the subarray
 * @value: value to search for
 * Return: on success - index of value
 *         on failure(if not found) - -1.
 *
 * Description:
 *
 * This function recursively searches for a value in a sorted array
 * using the binary search algorithm. It prints the subarray being
 * searched after each change.
 *
 * If the value is found, it returns the index.
 * If not found, it returns -1.
 */

int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (binary_recursive(array, left, i, value));
	return (binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - searches for a value in a sorted array
 * @array: pointer to the first element of the array
 * @size: represents the size of the array.
 * @value: represents value to be searched.
 * Return: on success - the first index where value is found
 *         on failure(if not found/NuLL) - -1.
 * Description:
 *
 * Prints the [sub]array being searched after each change.
 * The function advanced_binary performs advanced binary search on
 * the sorted integer array for the value.
 * If array is NULL or size is 0, it returns -1.
 * Otherwise, it calls binary_recursive with appropriate arguments.
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
