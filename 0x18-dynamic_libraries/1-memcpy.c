#include "main.h"

/**
*_memcpy - USED TO COPY n bytes
* from memory area src to memory area dest
*@dest:DESTINATION
*@src:SOURCE
*@n:NUMBER OF BYTES.
*Return: POINTER OF n.
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
