#include "search_algos.h"

/**
 * binary_search_algo - uses binary search algorithm.
 * @array: represents an array of integers.
 * @left: represents the left element
 * @right: represents the right element
 * @value: represents the value to be searched.
 * Return: on success - index of value
 *         on failure(if not found) - -1.
 */

int binary_search_algo(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return (-1);
}

/**
 * exponential_search - A function that searches for a value
 *  in a sorted array using exponential search algorithm.
 * @array: pointer to the first element of the array
 * @size:  represents the size of the array.
 * @value: represents the value to be searched.
 * Return: returns the first index where value is found.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (binary_search_algo(array, i / 2, right, value));
}
