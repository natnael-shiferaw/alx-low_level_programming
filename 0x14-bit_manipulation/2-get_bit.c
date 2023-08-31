#include "main.h"

/**
* get_bit - Returns the value of a bit at a given index.
* @n: The number to retrieve the bit from.
* @index: The index of the bit to retrieve.
*
* Return: The value of the bit at the given index, or -1 on error.
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}
