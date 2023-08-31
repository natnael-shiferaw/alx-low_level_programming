#include "main.h"

/**
* get_endianness - Checks the endianness of the system.
*
* Return: 0 If Big Endian, 1 if little endian.
*/
int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *ptr = (unsigned char *)&num;

	if (*ptr)
		return (1);
	else
		return (0);
}
