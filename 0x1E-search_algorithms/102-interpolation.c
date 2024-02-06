#include "search_algos.h"

/**
 *interpolation_search - A function that is used to search for
 *                     a value in a sorted array.
 * @array: pointer to the first element of the array
 * @size:  represents the size of the array.
 * @value: represents the value to be searched.
 * Return: returns the first index where value is found.
 *
 * Description:
 *
 * This function performs interpolation search on a sorted integer array.
 * It checks for NULL array or empty size and returns -1 if so.
 * It initializes search range indices and performs the main loop
 * until the search range is non-empty and value is within it.
 * Within each iteration, it calculates the probe position using
 * interpolation formula, compares the value at that position,
 * and updates the search range accordingly.
 * If the value is found, it returns its index; otherwise, it returns -1.
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t j, i, r;

	if (array == NULL)
		return (-1);

	for (i = 0, r = size - 1; r >= i;)
	{
		j = i + (((double)(r - i) / (array[r] - array[i])) * (value - array[i]));
		if (j < size)
			printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", j);
			break;
		}

		if (array[j] == value)
			return (j);
		if (array[j] > value)
			r = j - 1;
		else
			i = j + 1;
	}

	return (-1);
}
