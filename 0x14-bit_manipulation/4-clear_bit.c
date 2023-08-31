#include "main.h"

/**
* clear_bit - Sets the value of a bit to 0 at a given index.
* @n: Pointer to the number where the bit is to be cleared.
* @index: is The Index of the bit to clear.
*
* Return: 1 If Successful, or -1 on ERROR.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
